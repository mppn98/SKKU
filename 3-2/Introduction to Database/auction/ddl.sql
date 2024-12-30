-- Users 테이블: 관리자 및 일반 사용자 구분
CREATE TABLE Users (
    user_id VARCHAR(20) NOT NULL,
    password VARCHAR(255) NOT NULL,
    check_admin BOOLEAN DEFAULT FALSE,
    number_sold_items INT DEFAULT 0,
    number_buy_items INT DEFAULT 0,
    PRIMARY KEY (user_id)
);

-- Items 테이블: 제품 정보 포함
CREATE TABLE Items (
    item_id SERIAL PRIMARY KEY,
    category VARCHAR(50) NOT NULL
        CHECK (category IN ('ELECTRONICS', 'BOOKS', 'HOME', 'CLOTHING', 'SPORTING GOODS')),
    description TEXT NOT NULL,
    condition VARCHAR(50) NOT NULL
        CHECK (condition IN ('NEW', 'LIKE_NEW', 'GOOD', 'ACCEPTABLE')),
    seller_id VARCHAR(20) NOT NULL REFERENCES Users(user_id),
    bid_price NUMERIC(10, 2) CHECK (bid_price >= 0), --현재 가격
    buy_it_now_price NUMERIC(10, 2) NOT NULL CHECK (buy_it_now_price >= 0), --즉시 구매가
    floor_price NUMERIC(10, 2) DEFAULT 0 CHECK (floor_price >= 0), --최저가
    number_bid INT DEFAULT 0,  --입찰 횟수
    date_posted TIMESTAMP DEFAULT CURRENT_TIMESTAMP, --등록 날짜
    bid_closing_date TIMESTAMP, --마감 날짜
    status VARCHAR(50) DEFAULT 'active' CHECK (status IN ('active', 'sold')) -- 'active' 또는 'sold'
);

-- Bids 테이블: 입찰 내역 관리
CREATE TABLE Bids (
    bid_id SERIAL PRIMARY KEY,
    item_id INT NOT NULL REFERENCES Items(item_id),
    bidder_id VARCHAR(20) NOT NULL REFERENCES Users(user_id),
    bid_price NUMERIC(10, 2) NOT NULL CHECK (bid_price >= 0), --입찰가
    date_posted TIMESTAMP DEFAULT CURRENT_TIMESTAMP --입찰 날짜
);

-- Billing 테이블: 거래 내역 관리
CREATE TABLE Billing (
    billing_id SERIAL PRIMARY KEY,
    sold_item_id INT NOT NULL REFERENCES Items(item_id),
    seller_id VARCHAR(20) NOT NULL REFERENCES Users(user_id),
    buyer_id VARCHAR(20) NOT NULL REFERENCES Users(user_id),
    sold_price NUMERIC(10, 2) NOT NULL CHECK (sold_price >= 0), -- 판매가
    purchase_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    amount_due NUMERIC(10, 2) CHECK (amount_due >= 0), -- 구매자가 지불해야 하는 금액
    amount_paid NUMERIC(10, 2) CHECK (amount_paid >= 0) -- 판매자가 받는 금액
);

---- 추가된 테이블 ----
CREATE TABLE CloseBids (
    bid_id SERIAL PRIMARY KEY,
    item_id INT NOT NULL REFERENCES Items(item_id),
    bidder_id VARCHAR(20) NOT NULL REFERENCES Users(user_id),
    bid_price NUMERIC(10, 2) NOT NULL CHECK (bid_price >= 0), -- 종료된 입찰가
    date_posted TIMESTAMP DEFAULT CURRENT_TIMESTAMP -- 종료된 입찰 날짜
);
