import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.Timestamp;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.time.Duration;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.text.*;
import java.util.*;

import javax.naming.spi.DirStateFactory.Result;

public class Auction {
	private static Scanner scanner = new Scanner(System.in);
	private static String username;
	private static Connection conn;
	private static String status = "active";;

	enum Category {
		ELECTRONICS,
		BOOKS,
		HOME,
		CLOTHING,
		SPORTINGGOODS,
		OTHERS
	}

	enum Condition {
		NEW,
		LIKE_NEW,
		GOOD,
		ACCEPTABLE
	}

	private static boolean LoginMenu() {
		String userpass;

		Boolean isAdmin;

		System.out.print("----< User Login >\n" +
				" ** To go back, enter 'back' in user ID.\n" +
				"     user ID: ");
		try {
			username = scanner.next();
			scanner.nextLine();

			if (username.equalsIgnoreCase("back")) {
				return false;
			}

			System.out.print("     password: ");
			userpass = scanner.next();
			scanner.nextLine();
		} catch (java.util.InputMismatchException e) {
			System.out.println("Error: Invalid input is entered. Try again.");
			username = null;
			return false;
		}

		/* Your code should come here to check ID and password */
		// 사용자 ID와 비밀번호 확인 쿼리
		String query = "SELECT * FROM Users WHERE (user_id = ?) AND (password = ?)";
		String check_Admin = null;

		try {
			PreparedStatement preparedStatement = conn.prepareStatement(query);
			preparedStatement.setString(1, username);
			preparedStatement.setString(2, userpass);

			ResultSet rs = preparedStatement.executeQuery();
			if (!rs.next()) {
				// 로그인 실패
				System.out.println("\nAccess denied: Username/password is incorrect\n");
				return false;
			} else {
				// check_admin
				isAdmin = rs.getBoolean("check_admin");
				if (isAdmin) {
					System.out.print("Login as administrator? (y/n):");
					check_Admin = scanner.next();
					scanner.nextLine();
				}

				// 관리자로 로그인일 경우
				if ("y".equalsIgnoreCase(check_Admin)) {
					System.out.println("Choose administrator login mode.\n");
					return false;
				}

				// 로그인 success
				System.out.println("You are successfully logged in.\n");
				return true;
			}
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
	}

	private static boolean SellMenu() {
		Category category = null;
		Condition condition = null;
		char choice;
		int price;
		boolean flag_catg = true, flag_cond = true;
		String description = null;
		LocalDateTime dateTime = null;

		do {
			System.out.println(
					"----< Sell Item >\n" +
							"---- Choose a category.\n" +
							"    1. Electronics\n" +
							"    2. Books\n" +
							"    3. Home\n" +
							"    4. Clothing\n" +
							"    5. Sporting Goods\n" +
							"    6. Other Categories\n" +
							"    P. Go Back to Previous Menu");

			try {
				choice = scanner.next().charAt(0);
				;
			} catch (java.util.InputMismatchException e) {
				System.out.println("Error: Invalid input is entered. Try again.");
				continue;
			}

			flag_catg = true;

			switch ((int) choice) {
				case '1':
					category = Category.ELECTRONICS;
					continue;
				case '2':
					category = Category.BOOKS;
					continue;
				case '3':
					category = Category.HOME;
					continue;
				case '4':
					category = Category.CLOTHING;
					continue;
				case '5':
					category = Category.SPORTINGGOODS;
					continue;
				case '6':
					category = Category.OTHERS;
					continue;
				case 'p':
				case 'P':
					return false;
				default:
					System.out.println("Error: Invalid input is entered. Try again.");
					flag_catg = false;
					continue;
			}
		} while (!flag_catg);

		do {
			System.out.println(
					"---- Select the condition of the item to sell.\n" +
							"   1. New\n" +
							"   2. Like-new\n" +
							"   3. Used (Good)\n" +
							"   4. Used (Acceptable)\n" +
							"   P. Go Back to Previous Menu");

			try {
				choice = scanner.next().charAt(0);
				;
				scanner.nextLine();
			} catch (java.util.InputMismatchException e) {
				System.out.println("Error: Invalid input is entered. Try again.");
				continue;
			}

			flag_cond = true;

			switch (choice) {
				case '1':
					condition = Condition.NEW;
					break;
				case '2':
					condition = Condition.LIKE_NEW;
					break;
				case '3':
					condition = Condition.GOOD;
					break;
				case '4':
					condition = Condition.ACCEPTABLE;
					break;
				case 'p':
				case 'P':
					return false;
				default:
					System.out.println("Error: Invalid input is entered. Try again.");
					flag_cond = false;
					continue;
			}
		} while (!flag_cond);

		try {
			System.out.println("---- Description of the item (one line): ");
			description = scanner.nextLine();

			System.out.println("---- Buy-It-Now price: ");
			while (!scanner.hasNextInt()) {
				scanner.next();
				System.out.println("Invalid input is entered. Please enter Buy-It-Now price: ");
			}

			price = scanner.nextInt();
			scanner.nextLine();

			System.out.print("---- Bid closing date and time (YYYY-MM-DD HH:MM:ss): ");
			// you may assume users always enter valid date/time
			String date = scanner.nextLine(); /* "2023-03-04 11:30"; */
			DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
			dateTime = LocalDateTime.parse(date, formatter);
		} catch (Exception e) {
			System.out.println("Error: Invalid input is entered. Going back to the previous menu.");
			return false;
		}

		/* TODO: Your code should come here to store the user inputs in your database */
		try {
			String insertQuery = "INSERT INTO Items (category, description, condition, seller_id, bid_price, buy_it_now_price, floor_price, number_bid, date_posted, bid_closing_date, status) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

			PreparedStatement preparedStatement = conn.prepareStatement(insertQuery);

			preparedStatement.setString(1, category.name()); // Enum 값인 category를 문자열로 변환해 저장
			preparedStatement.setString(2, description); // 설명
			preparedStatement.setString(3, condition.name()); // Enum 값인 condition을 문자열로 변환해 저장
			preparedStatement.setString(4, username); // 현재 로그인된 사용자 ID를 seller_id로 사용
			preparedStatement.setBigDecimal(5, BigDecimal.ZERO); // 입찰가
			preparedStatement.setBigDecimal(6, BigDecimal.valueOf(price)); // 즉시 구매가
			preparedStatement.setBigDecimal(7, BigDecimal.ZERO); // 최저가를 0으로 초기화
			preparedStatement.setInt(8, 0); // 초기 입찰 횟수는 0으로 설정
			preparedStatement.setTimestamp(9, Timestamp.valueOf(LocalDateTime.now().withNano(0))); // date_posted, 소수점
																									// 제거
			preparedStatement.setTimestamp(10, Timestamp.valueOf(dateTime)); // 마감 날짜 및 시간
			preparedStatement.setString(11, status); // 상태

			int rowsAffected = preparedStatement.executeUpdate();
			if (rowsAffected > 0) {
				System.out.println("Item has been successfully listed.\n");
			} else {
				System.out.println("Database error: Unable to save item information.\n");
			}

		} catch (Exception e) {
			e.printStackTrace();
			System.out.println("Database error: Unable to save item information.\n");
			return false;
		}

		System.out.println("Your item has been successfully listed.\n");
		return true;
	}

	private static boolean SignupMenu() {
		/* 2. Sign Up */
		String new_username, userpass, isAdmin;
		System.out.print("----< Sign Up >\n" +
				" ** To go back, enter 'back' in user ID.\n" +
				"---- user name: ");
		try {
			new_username = scanner.next();
			scanner.nextLine();
			if (new_username.equalsIgnoreCase("back")) {
				return false;
			}
			System.out.print("---- password: ");
			userpass = scanner.next();
			scanner.nextLine();
			System.out.print("---- In this user an administrator? (Y/N): ");
			isAdmin = scanner.next();
			scanner.nextLine();
		} catch (java.util.InputMismatchException e) {
			System.out.println("Error: Invalid input is entered. Please select again.");
			return false;
		}

		/* TODO: Your code should come here to create a user account in your database */
		try {
			String insertQuery = "INSERT INTO Users (user_id, password, check_admin) VALUES (?, ?, ?)";
			PreparedStatement preparedStatement = conn.prepareStatement(insertQuery);

			preparedStatement.setString(1, new_username); // 사용자 ID
			preparedStatement.setString(2, userpass); // 비밀번호
			preparedStatement.setBoolean(3, isAdmin.equalsIgnoreCase("Y")); // 관리자인지 여부

			int rowsAffected = preparedStatement.executeUpdate();
			if (rowsAffected > 0) {
				System.out.println("Your account has been successfully created.\n");
			} else {
				System.out.println("Error: Unable to create account.\n");
				return false;
			}
		} catch (SQLException e) {
			// 중복 키 오류
			if (e.getSQLState().equals("23505")) {
				System.out.println("Error: This user ID is already taken. Please choose a different ID.\n");
			} else {
				System.out.println("Database error: Unable to save account information. Please try again.\n");
			}
			return false;
		}
		return true;
	}

	private static boolean AdminMenu() {
		/* 3. Login as Administrator */
		char choice;
		String adminname, adminpass;
		String keyword, seller;
		System.out.print("----< Login as Administrator >\n" +
				" ** To go back, enter 'back' in user ID.\n" +
				"---- admin ID: ");

		try {
			adminname = scanner.next();
			scanner.nextLine();
			if (adminname.equalsIgnoreCase("back")) {
				return false;
			}
			System.out.print("---- password: ");
			adminpass = scanner.nextLine();
		} catch (java.util.InputMismatchException e) {
			System.out.println("Error: Invalid input is entered. Try again.");
			return false;
		}

		String login_query = "SELECT * FROM Users WHERE user_id = ? AND password = ? AND check_admin = true";

		try (PreparedStatement preparedStatement = conn.prepareStatement(login_query)) {
			preparedStatement.setString(1, adminname);
			preparedStatement.setString(2, adminpass);

			try (ResultSet rs = preparedStatement.executeQuery()) {
				if (rs.next()) {
					System.out.println("Admin login successful.\n");
				} else {
					System.out.println("Error: Incorrect user name or password or you are not admin");
					return false;
				}
			}
		} catch (SQLException e) {
			System.out.println("Database error: Unable to verify as administrator.");
			e.printStackTrace();
			return false;
		}

		do {
			System.out.println(
					"----< Admin menu > \n" +
							"    1. Print Sold Items per Category \n" +
							"    2. Print Account Balance for Seller \n" +
							"    3. Print Seller Ranking \n" +
							"    4. Print Buyer Ranking \n" +
							"    P. Go Back to Previous Menu");

			try {
				choice = scanner.next().charAt(0);
				;
				scanner.nextLine();
			} catch (java.util.InputMismatchException e) {
				System.out.println("Error: Invalid input is entered. Try again.");
				continue;
			}

			if (choice == '1') {

				System.out.println("----Enter Category to search : ");
				keyword = scanner.next();
				scanner.nextLine();
				/* TODO: Print Sold Items per Category */
				System.out
						.println("sold item       | sold date       | seller ID   | buyer ID   | price | commissions");
				System.out
						.println("----------------------------------------------------------------------------------");

				String query = "SELECT b.sold_item_id AS item_id, b.purchase_date AS sold_date, b.seller_id, b.buyer_id, "
						+
						"b.sold_price AS price, FLOOR(b.sold_price * 0.1) AS commission " +
						"FROM Billing AS b " +
						"JOIN Items AS i ON b.sold_item_id = i.item_id " +
						"WHERE i.category = ?";

				try (PreparedStatement preparedStatement = conn.prepareStatement(query)) {

					preparedStatement.setString(1, keyword);
					ResultSet rs = preparedStatement.executeQuery();

					while (rs.next()) {
						System.out.printf("%-15s | %-15s | %-10s | %-10s | %-10.2f | %-10.2f%n",
								rs.getString("item_id"),
								rs.getTimestamp("sold_date"),
								rs.getString("seller_id"),
								rs.getString("buyer_id"),
								rs.getDouble("price"),
								rs.getDouble("commission"));
					}
				} catch (SQLException e) {
					System.out.println("Database error: Unable to retrieve sold items.");
				}
				continue;

			} else if (choice == '2') {
				/* TODO: Print Account Balance for Seller */
				System.out.println("---- Enter Seller ID to search : ");
				seller = scanner.next();
				scanner.nextLine();

				System.out.println("sold item       | sold date       | buyer ID   | price | commissions");
				System.out.println("--------------------------------------------------------------------");

				String query = "SELECT sold_item_id AS item_id, purchase_date AS sold_date, buyer_id, sold_price AS price, ROUND(sold_price * 0.1, 1) AS commission "
						+
						"FROM Billing WHERE seller_id = ?";

				try (PreparedStatement preparedStatement = conn.prepareStatement(query)) {
					preparedStatement.setString(1, seller);
					ResultSet rs = preparedStatement.executeQuery();

					while (rs.next()) {
						System.out.printf("%-15s | %-15s | %-10s | %-10.2f | %-10.2f%n",
								rs.getString("item_id"),
								rs.getTimestamp("sold_date"),
								rs.getString("buyer_id"),
								rs.getDouble("price"),
								rs.getDouble("commission"));
					}
				} catch (SQLException e) {
					System.out.println("Database error: Unable to retrieve account balance for seller.");
					e.printStackTrace();
				}
				continue;

			} else if (choice == '3') {
				/* TODO: Print Seller Ranking */
				System.out.println("seller ID   | # of items sold | Total Profit (excluding commissions)");
				System.out.println("--------------------------------------------------------------------");

				String query = "SELECT seller_id, COUNT(sold_item_id) AS items_sold, SUM(sold_price - sold_price * 0.1) AS total_profit "
						+
						"FROM Billing GROUP BY seller_id ORDER BY total_profit DESC";

				try (PreparedStatement preparedStatement = conn.prepareStatement(query)) {
					ResultSet rs = preparedStatement.executeQuery();

					while (rs.next()) {
						System.out.printf("%-12s | %-15d | %-10.2f%n",
								rs.getString("seller_id"),
								rs.getInt("items_sold"),
								rs.getDouble("total_profit"));
					}
				} catch (SQLException e) {
					e.printStackTrace();
				}
				continue;

			} else if (choice == '4') {
				/* TODO: Print Buyer Ranking */
				System.out.println("buyer ID   | # of items purchased | Total Money Spent ");
				System.out.println("------------------------------------------------------");

				String query = "SELECT buyer_id, COUNT(sold_item_id) AS items_purchased, SUM(sold_price) AS total_spent "
						+
						"FROM Billing GROUP BY buyer_id ORDER BY total_spent DESC";

				try (PreparedStatement preparedStatement = conn.prepareStatement(query)) {
					ResultSet rs = preparedStatement.executeQuery();

					while (rs.next()) {
						System.out.printf("%-10s | %-20d | %-15.2f%n",
								rs.getString("buyer_id"),
								rs.getInt("items_purchased"),
								rs.getDouble("total_spent"));
					}
				} catch (SQLException e) {
					e.printStackTrace();
				}
				continue;

			} else if (choice == 'P' || choice == 'p') {
				return false;
			} else {
				System.out.println("Error: Invalid input is entered. Try again.");
				continue;
			}
		} while (true);
	}

	public static void CheckSellStatus() {
		System.out.println("item listed in Auction | bidder (buyer ID) | bidding price | bidding date/time");
		System.out.println("-------------------------------------------------------------------------------");

		// 판매자의 아이템에 대해 입찰된 정보를 조회하는 쿼리
		String query = "SELECT i.item_id, i.status, b.bidder_id, b.bid_price, b.date_posted " +
				"FROM Items AS i " +
				"LEFT JOIN Bids AS b ON i.item_id = b.item_id " +
				"WHERE i.seller_id = ? AND i.status = 'active' ";

		try (PreparedStatement PreparedStatement = conn.prepareStatement(query)) {
			PreparedStatement.setString(1, username); // 현재 로그인된 사용자의 아이디를 seller_id로 설정
			ResultSet rs = PreparedStatement.executeQuery();

			DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:MM:SS");

			// 조회 결과를 반복하면서 출력
			while (rs.next()) {
				int item_id = rs.getInt("item_id");
				String bidder_id = rs.getString("bidder_id");
				BigDecimal bid_price = rs.getBigDecimal("bid_price");
				Timestamp bid_date = rs.getTimestamp("date_posted");

				System.out.printf("%-20d | %-15s | %-15.2f | %-20s%n",
						item_id,
						bidder_id != null ? bidder_id : "No Bids", // Null check for bidder_id
						bid_price != null ? bid_price : 0.0, // Null check for bid_price
						bid_date != null ? bid_date.toLocalDateTime().format(formatter) : "N/A" // Null check for
																								// bid_date
				);
			}
		} catch (SQLException e) {
			System.out.println("Database error: Unable to retrieve bidding status.");
			e.printStackTrace();
		}
	}

	public static boolean BuyItem() {
		Category category = null;
		Condition condition = null;
		char choice;
		int price;
		String keyword, seller, datePosted;
		boolean flag_catg = true, flag_cond = true;

		do {

			System.out.println("----< Select category > : \n" +
					"    1. Electronics\n" +
					"    2. Books\n" +
					"    3. Home\n" +
					"    4. Clothing\n" +
					"    5. Sporting Goods\n" +
					"    6. Other categories\n" +
					"    7. Any category\n" +
					"    P. Go Back to Previous Menu");

			try {
				choice = scanner.next().charAt(0);
				;
				scanner.nextLine();
			} catch (java.util.InputMismatchException e) {
				System.out.println("Error: Invalid input is entered. Try again.");
				return false;
			}

			flag_catg = true;

			switch (choice) {
				case '1':
					category = Category.ELECTRONICS;
					break;
				case '2':
					category = Category.BOOKS;
					break;
				case '3':
					category = Category.HOME;
					break;
				case '4':
					category = Category.CLOTHING;
					break;
				case '5':
					category = Category.SPORTINGGOODS;
					break;
				case '6':
					category = Category.OTHERS;
					break;
				case '7':
					break;
				case 'p':
				case 'P':
					return false;
				default:
					System.out.println("Error: Invalid input is entered. Try again.");
					flag_catg = false;
					continue;
			}
		} while (!flag_catg);

		do {

			System.out.println(
					"----< Select the condition > \n" +
							"   1. New\n" +
							"   2. Like-new\n" +
							"   3. Used (Good)\n" +
							"   4. Used (Acceptable)\n" +
							"   P. Go Back to Previous Menu");
			try {
				choice = scanner.next().charAt(0);
				;
				scanner.nextLine();
			} catch (java.util.InputMismatchException e) {
				System.out.println("Error: Invalid input is entered. Try again.");
				return false;
			}

			flag_cond = true;

			switch (choice) {
				case '1':
					condition = Condition.NEW;
					break;
				case '2':
					condition = Condition.LIKE_NEW;
					break;
				case '3':
					condition = Condition.GOOD;
					break;
				case '4':
					condition = Condition.ACCEPTABLE;
					break;
				case 'p':
				case 'P':
					return false;
				default:
					System.out.println("Error: Invalid input is entered. Try again.");
					flag_cond = false;
					continue;
			}
		} while (!flag_cond);

		try {
			System.out.println("---- Enter keyword to search the description : ");
			keyword = scanner.next();
			scanner.nextLine();

			System.out.println("---- Enter Seller ID to search : ");
			System.out.println(" ** Enter 'any' if you want to see items from any seller. ");
			seller = scanner.next();
			scanner.nextLine();

			System.out.println("---- Enter date posted (YYYY-MM-DD): ");
			System.out.println(" ** This will search items that have been posted after the designated date.");
			datePosted = scanner.next();
			scanner.nextLine();
		} catch (java.util.InputMismatchException e) {
			System.out.println("Error: Invalid input is entered. Try again.");
			return false;
		}

		// Query items
		/* TODO: Query condition: item category */
		/* TODO: Query condition: item condition */
		/*
		 * TODO: Query condition: items whose description match the keyword (use LIKE
		 * operator)
		 */
		/* TODO: Query condition: items from a particular seller */
		/* TODO: Query condition: posted date of item */

		/* TODO: List all items that match the query condition */
		System.out.println(
				"Item ID | Item description | Condition | Seller | Buy-It-Now | Current Bid | highest bidder | Time left | bid close");
		System.out.println(
				"-------------------------------------------------------------------------------------------------------");

		StringBuilder query = new StringBuilder(
				"SELECT i.item_id, i.description, i.condition, i.seller_id, i.buy_it_now_price, " +
						"COALESCE(MAX(b.bid_price), 0) AS current_bid, COALESCE(MAX(b.bidder_id), 'No Bids') AS highest_bidder, i.bid_closing_date "
						+
						"FROM Items AS i LEFT JOIN Bids AS b ON i.item_id = b.item_id WHERE i.date_posted >= ? ");

		if (category != null) {
			query.append("AND i.category = ? ");
		}
		if (condition != null) {
			query.append("AND i.condition = ? ");
		}
		query.append("AND i.description LIKE ? ");
		if (!seller.equalsIgnoreCase("any")) {
			query.append("AND i.seller_id = ? ");
		}
		query.append(
				"GROUP BY i.item_id, i.description, i.condition, i.seller_id, i.buy_it_now_price, i.bid_closing_date");

		Timestamp datePostedTimestamp = Timestamp.valueOf(datePosted + " 00:00:00");

		try (PreparedStatement pstmt = conn.prepareStatement(query.toString())) {
			int paramIndex = 1;
			pstmt.setTimestamp(paramIndex++, datePostedTimestamp);

			if (category != null)
				pstmt.setString(paramIndex++, category.name());
			if (condition != null)
				pstmt.setString(paramIndex++, condition.name());
			pstmt.setString(paramIndex++, "%" + keyword + "%");
			if (!seller.equalsIgnoreCase("any"))
				pstmt.setString(paramIndex, seller);

			ResultSet rs = pstmt.executeQuery();

			// Display items that match search criteria
			while (rs.next()) {
				LocalDateTime bidClosingDate = rs.getTimestamp("bid_closing_date").toLocalDateTime();
				Duration timeLeft = Duration.between(LocalDateTime.now(), bidClosingDate);
				String timeLeftStr = timeLeft.isNegative() ? "Closed" : String.format("%d hours", timeLeft.toHours());

				System.out.printf("%-10d | %-20s | %-10s | %-10s | %-10.2f | %-10.2f | %-15s | %-10s | %-10s%n",
						rs.getInt("item_id"),
						rs.getString("description"),
						rs.getString("condition"),
						rs.getString("seller_id"),
						rs.getDouble("buy_it_now_price"),
						rs.getDouble("current_bid"),
						rs.getString("highest_bidder"),
						timeLeftStr,
						bidClosingDate.toString());
			}

		} catch (SQLException e) {
			System.out.println("Database error: Unable to retrieve items.");
			e.printStackTrace();
		}
		/*
		 * while(rset.next()){
		 * }
		 */

		System.out.println("---- Select Item ID to buy or bid: ");

		int selectedItemID;
		try {
			selectedItemID = scanner.nextInt();
			scanner.nextLine();
			System.out.println("     Price: ");
			price = scanner.nextInt();
			scanner.nextLine();
		} catch (java.util.InputMismatchException e) {
			System.out.println("Error: Invalid input is entered. Try again.");
			return false;
		}

		try {
			// Retrieve Buy-It-Now price to determine if the bid is valid
			String binQuery = "SELECT buy_it_now_price, bid_closing_date FROM Items WHERE item_id = ?";
			PreparedStatement binStmt = conn.prepareStatement(binQuery);
			binStmt.setInt(1, selectedItemID);
			ResultSet rs = binStmt.executeQuery();

			if (rs.next()) {
				double buyItNowPrice = rs.getDouble("buy_it_now_price");
				LocalDateTime bidClosingDate = rs.getTimestamp("bid_closing_date").toLocalDateTime();

				// Check if the bid closing date has passed
				if (LocalDateTime.now().isAfter(bidClosingDate)) {
					System.out.println("Bid Ended");
					return false; // Exit the method as the bid has ended
				}

				if (price >= buyItNowPrice) {
					System.out.println("Congratulations, the item is yours now.\n");

					// 거래 완료 로직
					double amountDue = buyItNowPrice;
					double amountPaid = buyItNowPrice - Math.floor(buyItNowPrice * 0.1);
					String insertBilling = "INSERT INTO Billing (sold_item_id, seller_id, buyer_id, sold_price, amount_due, amount_paid, purchase_date) "
							+
							"VALUES (?, ?, ?, ?, ?, ?, CAST(CURRENT_TIMESTAMP AS TIMESTAMP(0)))";
					PreparedStatement billingStmt = conn.prepareStatement(insertBilling);
					billingStmt.setInt(1, selectedItemID);
					billingStmt.setString(2, seller);
					billingStmt.setString(3, username);
					billingStmt.setDouble(4, buyItNowPrice);
					billingStmt.setDouble(5, amountDue);
					billingStmt.setDouble(6, amountPaid);
					billingStmt.executeUpdate();

					// 거래 완료 후 판매자와 구매자의 item count 업데이트

					// Items 테이블의 status를 'sold'로 업데이트
					String updateItemStatus = "UPDATE Items SET status = 'sold' WHERE item_id = ?";
					PreparedStatement updateStatusStmt = conn.prepareStatement(updateItemStatus);
					updateStatusStmt.setInt(1, selectedItemID);
					updateStatusStmt.executeUpdate();

					// 거래 완료 후 Items 테이블의 number_bid 증가
					String updateNumberBid = "UPDATE Items SET number_bid = number_bid + 1 WHERE item_id = ?";
					PreparedStatement updateBidStmt = conn.prepareStatement(updateNumberBid);
					updateBidStmt.setInt(1, selectedItemID);
					updateBidStmt.executeUpdate();

					// 판매자의 number_sold_items 증가
					String updateSellerCount = "UPDATE Users SET number_sold_items = number_sold_items + 1 WHERE user_id = ?";
					PreparedStatement updateSellerStmt = conn.prepareStatement(updateSellerCount);
					updateSellerStmt.setString(1, seller);
					updateSellerStmt.executeUpdate();

					// 구매자의 number_buy_items 증가
					String updateBuyerCount = "UPDATE Users SET number_buy_items = number_buy_items + 1 WHERE user_id = ?";
					PreparedStatement updateBuyerStmt = conn.prepareStatement(updateBuyerCount);
					updateBuyerStmt.setString(1, username); // 현재 구매자 ID로 설정
					updateBuyerStmt.executeUpdate();

					// CloseBids 테이블에 입찰 정보 이동
					String closeBidsQuery = "INSERT INTO CloseBids (item_id, bidder_id, bid_price, date_posted) " +
							"SELECT item_id, bidder_id, bid_price, CAST(date_posted AS TIMESTAMP(0)) FROM Bids WHERE item_id = ?";
					PreparedStatement closeBidsStmt = conn.prepareStatement(closeBidsQuery);
					closeBidsStmt.setInt(1, selectedItemID);
					closeBidsStmt.executeUpdate();

					// Bids 테이블에서 해당 항목 삭제
					String deleteBids = "DELETE FROM Bids WHERE item_id = ?";
					PreparedStatement deleteStmt = conn.prepareStatement(deleteBids);
					deleteStmt.setInt(1, selectedItemID);
					deleteStmt.executeUpdate();

				} else {
					System.out.println("Congratulations, you are the highest bidder.\n");
					// 입찰 기록 추가 로직
					String insertBid = "INSERT INTO Bids (item_id, bidder_id, bid_price, date_posted) VALUES (?, ?, ?, CURRENT_TIMESTAMP)";
					PreparedStatement bidStmt = conn.prepareStatement(insertBid);
					bidStmt.setInt(1, selectedItemID);
					bidStmt.setString(2, username); // 현재 로그인된 사용자의 ID
					bidStmt.setDouble(3, price); // 사용자가 입력한 입찰 가격
					bidStmt.executeUpdate();

					// Items 테이블의 number_bid 증가
					String updateNumberBid = "UPDATE Items SET number_bid = number_bid + 1 WHERE item_id = ?";
					PreparedStatement updateBidStmt = conn.prepareStatement(updateNumberBid);
					updateBidStmt.setInt(1, selectedItemID);
					updateBidStmt.executeUpdate();
				}
			} else {
				System.out.println("Error: Selected item not found.");
				return false;
			}
		} catch (SQLException e) {
			System.out.println("Database error: Unable to process the bid.");
			e.printStackTrace();
		}

		return true;
	}
	/*
	 * TODO: Buy-it-now or bid: If the entered price is higher or equal to
	 * Buy-It-Now price, the bid ends.
	 */
	/*
	 * Even if the bid price is higher than the Buy-It-Now price, the buyer pays the
	 * B-I-N price.
	 */

	/* TODO: if you won, print the following */
	// System.out.println("Congratulations, the item is yours now.\n");
	/* TODO: if you are the current highest bidder, print the following */
	// System.out.println("Congratulations, you are the highest bidder.\n");
	// return true;
	// }

	public static void CheckBuyStatus() {
		/* TODO: Check the status of the item the current buyer is bidding on */
		/*
		 * Even if you are outbidded or the bid closing date has passed, all the items
		 * this user has bidded on must be displayed
		 */

		System.out.println(
				"item ID   | item description   | highest bidder | highest bidding price | your bidding price | bid closing date/time");
		System.out.println(
				"--------------------------------------------------------------------------------------------------------------------");
		/*
		 * while(rset.next(){
		 * System.out.println();
		 * }
		 */
		StringBuilder query = new StringBuilder(
				"SELECT i.item_id, i.description, " +
						"COALESCE(b1.bidder_id, 'No Bids') AS highest_bidder, " +
						"COALESCE(MAX(b1.bid_price), 0) AS highest_bidding_price, " +
						"b2.bid_price AS your_bidding_price, " +
						"i.bid_closing_date " +
						"FROM Items AS i " +
						"LEFT JOIN Bids AS b1 ON i.item_id = b1.item_id " +
						"LEFT JOIN Bids AS b2 ON i.item_id = b2.item_id AND b2.bidder_id = ? " +
						"WHERE b2.bidder_id = ? " +
						"GROUP BY i.item_id, i.description, b1.bidder_id, b2.bid_price, i.bid_closing_date");

		try (PreparedStatement pstmt = conn.prepareStatement(query.toString())) {
			pstmt.setString(1, username); // Set username for your bidding price
			pstmt.setString(2, username); // Set username for filtering items you bid on

			try (ResultSet rs = pstmt.executeQuery()) {
				while (rs.next()) {
					int itemId = rs.getInt("item_id");
					String description = rs.getString("description");
					String highestBidder = rs.getString("highest_bidder");
					double highestBiddingPrice = rs.getDouble("highest_bidding_price");
					double yourBiddingPrice = rs.getDouble("your_bidding_price");
					Timestamp bidClosingDate = rs.getTimestamp("bid_closing_date");

					// 마감 시간이 지나면 "Closed"로 표시하고, 남아있으면 시간 표시
					LocalDateTime closingDate = bidClosingDate.toLocalDateTime();
					String timeLeftStr = LocalDateTime.now().isAfter(closingDate) ? "Closed"
							: Duration.between(LocalDateTime.now(), closingDate).toHours() + " hours left";

					System.out.printf("%-10d | %-20s | %-15s | %-22.2f | %-19.2f | %-22s%n",
							itemId,
							description,
							highestBidder,
							highestBiddingPrice,
							yourBiddingPrice,
							timeLeftStr);
				}
			}
		} catch (SQLException e) {
			System.out.println("Database error: Unable to retrieve bidding status.");
			e.printStackTrace();
		}
	}

	public static void CheckAccount() {
		/* TODO: Check the balance of the current user. */
		System.out.println("[Sold Items] \n");
		System.out.println("item category  | item ID   | sold date | sold price  | buyer ID | commission  ");
		System.out.println("------------------------------------------------------------------------------");

		String soldItemsQuery = "SELECT i.category, b.sold_item_id, b.purchase_date, b.sold_price, b.buyer_id, " +
				"ROUND(b.sold_price * 0.1, 1) AS commission, " +
				"ROUND(b.sold_price - b.sold_price * 0.1, 0) AS net_amount_due, " +
				"i.bid_closing_date " +
				"FROM Billing AS b JOIN Items AS i ON b.sold_item_id = i.item_id " +
				"WHERE b.seller_id = ?";

		try (PreparedStatement pstmt = conn.prepareStatement(soldItemsQuery)) {
			pstmt.setString(1, username);
			try (ResultSet rs = pstmt.executeQuery()) {
				while (rs.next()) {
					String category = rs.getString("category");
					int itemId = rs.getInt("sold_item_id");
					Timestamp soldDate = rs.getTimestamp("purchase_date");
					double soldPrice = rs.getDouble("sold_price");
					String buyerId = rs.getString("buyer_id");
					double commission = rs.getDouble("commission");

					System.out.printf("%-15s | %-8d | %-12s | %-10.2f | %-10s | %-10.2f%n",
							category, itemId, soldDate.toLocalDateTime(), soldPrice, buyerId, commission);
				}
			}
		} catch (SQLException e) {
			System.out.println("Database error: Unable to retrieve sold items.");
			e.printStackTrace();
		}
		System.out.println("[Purchased Items] \n");
		System.out.println("item category  | item ID   | purchased date | puchased price  | seller ID ");
		System.out.println("--------------------------------------------------------------------------");

		String purchasedItemsQuery = "SELECT i.category, b.sold_item_id, b.purchase_date, b.sold_price, b.seller_id " +
				"FROM Billing AS b JOIN Items AS i ON b.sold_item_id = i.item_id " +
				"WHERE b.buyer_id = ?";

		try (PreparedStatement pstmt = conn.prepareStatement(purchasedItemsQuery)) {
			pstmt.setString(1, username);
			try (ResultSet rs = pstmt.executeQuery()) {
				while (rs.next()) {
					String category = rs.getString("category");
					int itemId = rs.getInt("sold_item_id");
					Timestamp purchaseDate = rs.getTimestamp("purchase_date");
					double purchasedPrice = rs.getDouble("sold_price");
					String sellerId = rs.getString("seller_id");

					System.out.printf("%-15s | %-8d | %-14s | %-16.2f | %-10s%n",
							category, itemId, purchaseDate.toLocalDateTime(), purchasedPrice, sellerId);
				}
			}
		} catch (SQLException e) {
			System.out.println("Database error: Unable to retrieve purchased items.");
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		char choice;
		boolean loggedIn = false;
		boolean ret = false;

		if (args.length < 2) {
			System.out.println("Usage: java Auction postgres_id password");
			System.exit(1);
		}

		try {
			conn = DriverManager.getConnection("jdbc:postgresql://localhost/" + args[0],
					args[0], args[1]);
			// Connection conn =
			// DriverManager.getConnection("jdbc:postgresql://localhost/s22315965",
			// "s22315965",
			// "juny2000");
		} catch (SQLException e) {
			System.out.println("SQLException : " + e);
			System.exit(1);
		}

		do {
			System.out.println(
					"----< Login menu >\n" +
							"----(1) Login\n" +
							"----(2) Sign up\n" +
							"----(3) Login as Administrator\n" +
							"----(Q) Quit");

			try {
				choice = scanner.next().charAt(0);
				scanner.nextLine();

				switch (choice) {
					case '1':
						loggedIn = LoginMenu();
						break;
					case '2':
						SignupMenu();
						break;
					case '3':
						AdminMenu();
						break;
					case 'q':
					case 'Q':
						System.out.println("Good Bye");
						if (conn != null && !conn.isClosed()) {
							conn.close();
							System.out.println("Database connection closed.");
						}
						scanner.close();
						System.exit(0);
					default:
						System.out.println("Error: Invalid input is entered. Try again.");
				}
			} catch (SQLException e) {
				System.out.println("SQLException : " + e);
			}
		} while (!loggedIn); // 로그인 성공 시에만 루프 종료

		// logged in as a normal user
		do {
			System.out.println(
					"---< Main menu > :\n" +
							"----(1) Sell Item\n" +
							"----(2) Status of Your Item Listed on Auction\n" +
							"----(3) Buy Item\n" +
							"----(4) Check Status of your Bid \n" +
							"----(5) Check your Account \n" +
							"----(Q) Quit");

			try {
				choice = scanner.next().charAt(0);
				;
				scanner.nextLine();
			} catch (java.util.InputMismatchException e) {
				System.out.println("Error: Invalid input is entered. Try again.");
				continue;
			}

			try {
				switch (choice) {
					case '1':
						ret = SellMenu();
						if (!ret)
							continue;
						break;
					case '2':
						CheckSellStatus();
						break;
					case '3':
						ret = BuyItem();
						if (!ret)
							continue;
						break;
					case '4':
						CheckBuyStatus();
						break;
					case '5':
						CheckAccount();
						break;
					case 'q':
					case 'Q':
						System.out.println("Good Bye");
						if (conn != null && !conn.isClosed()) {
							conn.close();
							System.out.println("Database connection closed.");
						}
						scanner.close(); // Close the scanner
						System.exit(0); // Exit the program
				}
			} catch (SQLException e) {
				System.out.println("SQLException : " + e);
				try {
					if (conn != null && !conn.isClosed()) {
						conn.close();
					}
				} catch (SQLException closeException) {
					System.out.println("Error closing connection: " + closeException.getMessage());
				}
				scanner.close(); // Close the scanner in case of error
				System.exit(1);
			}
		} while (true);
	} // End of main
} // End of class