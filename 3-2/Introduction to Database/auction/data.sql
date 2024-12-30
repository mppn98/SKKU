DELETE FROM Users;
INSERT INTO Users (user_id, password, check_admin, number_sold_items, number_buy_items) VALUES 
    ('admin', 'adminpass', TRUE, 0, 0),
    ('seller1', 'pass1', FALSE, 1, 0),  -- 판매 1개
    ('buyer1', 'pass2', FALSE, 0, 1),   -- 구매 1개
    ('buyer2', 'pass3', FALSE, 0, 1),   -- 구매 1개
    ('seller2', 'pass4', FALSE, 1, 0);  -- 판매 1개


DELETE FROM Items;
INSERT INTO Items (category, description, condition, seller_id, bid_price, buy_it_now_price, floor_price, number_bid, date_posted, bid_closing_date, status) VALUES
    ( 'ELECTRONICS', 'Latest model smartphone', 'NEW', 'seller1', 300.00, 500.00, 100.00, 2, '2024-10-10 09:00:00', '2024-10-20 18:00:00', 'active'),  -- number_bid = 2
    ( 'BOOKS', 'Bestselling fiction novel', 'LIKE_NEW', 'seller2', NULL, 20.00, NULL, 0, '2024-10-05 12:00:00', NULL, 'sold'),
    ( 'HOME', 'Wooden dining table', 'GOOD', 'seller1', 50.00, 150.00, 30.00, 1, '2024-10-12 14:30:00', '2024-10-22 18:00:00', 'active'),  -- number_bid = 1
    ( 'CLOTHING', 'Winter jacket', 'NEW', 'seller2', 40.00, 80.00, 20.00, 2, '2024-10-15 08:00:00', '2024-10-25 12:00:00', 'active'),   -- number_bid = 2
    ( 'SPORTING GOODS', 'Soccer ball', 'LIKE_NEW', 'seller1', NULL, 25.00, NULL, 0, '2024-10-02 09:00:00', NULL, 'sold');



DELETE FROM Bids;
INSERT INTO Bids (item_id, bidder_id, bid_price, date_posted) VALUES
    (1, 'buyer1', 120.00, '2024-10-10 10:00:00'),
    (1, 'buyer2', 150.00, '2024-10-11 15:00:00'),
    (3, 'buyer1', 60.00, '2024-10-12 16:00:00'),
    (4, 'buyer2', 45.00, '2024-10-15 09:30:00'),
    (4, 'buyer1', 50.00, '2024-10-16 11:00:00');

DELETE FROM Billing;
INSERT INTO Billing (sold_item_id, seller_id, buyer_id, sold_price, amount_due, amount_paid, purchase_date) VALUES
    (2, 'seller2', 'buyer1', 20.00, 20.00, 18.00, CAST('2024-11-13 19:54:41' AS TIMESTAMP(0))),
    (5, 'seller1', 'buyer2', 25.00, 25.00, 22.50, CAST('2024-11-13 19:54:41' AS TIMESTAMP(0)));


DELETE FROM CloseBids;
INSERT INTO CloseBids (item_id, bidder_id, bid_price, date_posted) VALUES
    (1, 'buyer2', 90.00, '2024-10-11 15:00:00'),
    (3, 'buyer1', 15.00, '2024-10-12 16:00:00');

SELECT * FROM Users;
SELECT * FROM Items;
SELECT * FROM Bids;
SELECT * FROM Billing;
SELECT * FROM CloseBids;
