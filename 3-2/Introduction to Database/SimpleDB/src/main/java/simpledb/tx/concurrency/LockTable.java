package simpledb.tx.concurrency;

import java.util.*;
import simpledb.file.BlockId;

/**
 * The lock table, which provides methods to lock and unlock blocks.
 * If a transaction requests a lock that causes a conflict with an
 * existing lock, then that transaction is placed on a wait list.
 * There is only one wait list for all blocks.
 * When the last lock on a block is unlocked, then all transactions
 * are removed from the wait list and rescheduled.
 * If one of those transactions discovers that the lock it is waiting for
 * is still locked, it will place itself back on the wait list.
 * @author Edward Sciore
 */
class LockTable {
   private static final long MAX_TIME = 10000; // 10 seconds
   
   private Map<BlockId,List<Integer>> locks = new HashMap<>();
   
   /**
    * Grant an SLock on the specified block.
    * If an XLock exists when the method is called,
    * then the calling thread will be placed on a wait list
    * until the lock is released.
    * If the thread remains on the wait list for a certain 
    * amount of time (currently 10 seconds),
    * then an exception is thrown.
    * @param blk a reference to the disk block
    */
   public synchronized void sLock(BlockId blk, int id) {
      try {
         long timestamp = System.currentTimeMillis();
         while (hasXlock(blk) && !waitingTooLong(timestamp)) {
            if (checkOlder(id, locks.get(blk))) {
               throw new LockAbortException();
            }
            wait(MAX_TIME);
         }
         if (hasXlock(blk)) {
            throw new LockAbortException();
         }
         List<Integer> addList = locks.getOrDefault(blk, new ArrayList<>());
         addList.add(id);
         locks.put(blk, addList);
      }
      catch(InterruptedException e) {
         throw new LockAbortException();
      }
   }
   
   /**
    * Grant an XLock on the specified block.
    * If a lock of any type exists when the method is called,
    * then the calling thread will be placed on a wait list
    * until the locks are released.
    * If the thread remains on the wait list for a certain 
    * amount of time (currently 10 seconds),
    * then an exception is thrown.
    * @param blk a reference to the disk block
    */
   synchronized void xLock(BlockId blk, int id) {
      try {
         long timestamp = System.currentTimeMillis();
         while (hasOtherSLocks(blk) && !waitingTooLong(timestamp)) {
            if (checkOlder(id, locks.get(blk))) {
               throw new LockAbortException();
            }
            wait(MAX_TIME);
         }
         if (hasOtherSLocks(blk)) {
            throw new LockAbortException();
         }
         List<Integer> list = new ArrayList<>();
         list.add(-id);
         locks.put(blk, list);
      }
      catch(InterruptedException e) {
         throw new LockAbortException();
      }
   }
   
   /**
    * Release a lock on the specified block.
    * If this lock is the last lock on that block,
    * then the waiting transactions are notified.
    * @param blk a reference to the disk block
    */
   synchronized void unlock(BlockId blk, int id) {
      List<Integer> list = locks.get(blk);
      if (list != null) {
         list.remove(Integer.valueOf(id));
         list.remove(Integer.valueOf(-id));
         if (list.isEmpty()) {
            locks.remove(blk);
            notifyAll();
         }
      }
   }
   
   private boolean hasXlock(BlockId blk) {
      List<Integer> list = locks.get(blk);
      if (list == null) {
         return false;
      }
      else {
         for (int i : list) {
            if (i < 0) {
               return true;
            }
         }
      }
      return false;
   }
   
   private boolean hasOtherSLocks(BlockId blk) {
      List<Integer> list = locks.get(blk);
      if (list == null) {
         return false;
      }
      else {
         for (int i : list) {
            if (i > 0) {
               if (list.size() > 1) {
                  return true;
               }
            }
         }
      }
      return false;
   }
   
   private boolean waitingTooLong(long starttime) {
      return System.currentTimeMillis() - starttime > MAX_TIME;
   }
   private boolean checkOlder(int id, List<Integer> list) {
      if (list == null) {
         return false;
      }
      else {
         for (int i : list) {
            if (i < id && i > 0) {
               return true;
            }
         }
         
      }
      return false;
   }
}
