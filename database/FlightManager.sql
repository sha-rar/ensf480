DROP DATABASE IF EXISTS FLIGHTMANAGER;
CREATE DATABASE FLIGHTMANAGER;

-- App login used by DatabaseManager.java (run this script as root once)
CREATE USER IF NOT EXISTS 'user'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON FLIGHTMANAGER.* TO 'user'@'localhost';
FLUSH PRIVILEGES;

USE FLIGHTMANAGER;

DROP TABLE IF EXISTS USER_ROLES;
CREATE TABLE USER_ROLES (
  RName         varchar(30) not null,
  primary key (RName)
);

INSERT INTO USER_ROLES (Rname)
VALUES
('Member'),
('Administrator'),
('Guest');

-- INCLUDES EXTRA USER INFO
DROP TABLE IF EXISTS USER_INFO;
CREATE TABLE USER_INFO (
  UserName      varchar(30) not null,
  PassWord      varchar(60) not null,     -- ideally stored as hash, real password never stored anywhere; not necessary for this demo
  Role          varchar(30) not null,
  Name          varchar(30) not null,
  Phone         char(12),
  Address       varchar(25),
  primary key (UserName),
  foreign key (Role) references USER_ROLES(RName)
);

INSERT INTO USER_INFO (UserName, PassWord, Role, Name, Phone, Address)
VALUES
('John316', 'VerryBerry@32', 'Member', 'John Doe', '909-293-4486', '28 Grove St. LA'),
('ironMaiden', 'fearoftheDARK99', 'Member', 'Bruce Dickinson', '909-495-6664', '486 Rolling Gr. LN'),
('MalcolmToddHobert', 'YouOweMe24''', 'Administrator', 'Malcolm Todd', '212-800-1856', '800 Lones Way LA');

DROP TABLE IF EXISTS FLIGHT_LISTINGS;
CREATE TABLE FLIGHT_LISTINGS (
  FlightID        varchar(12) not null,   -- 'PRYYMMDDHHMM' province/state, departure date and time, 12 characters total
                                          -- may need to change FlightID dynamically as flight details are changed through manager
  Destination     varchar(30) not null,    -- 'City PR'; City PRovince/STate; province/state always last two letters
  DepartureDate   DATE not null,    -- YYYY-MM-DD
  DepartureTime   TIME not null,    -- HH:MM:SS; 24 hour clock
  Duration        TIME,    -- HH:MM:SS
  ArrivalTime     TIME,    -- HH:MM:SS; local destination time
  Airline         varchar(30) not null,   -- ie. WestJet
  Price           DECIMAL(10, 2) not null check (Price >= 0),  -- CAD
  primary key (FlightID)
);

INSERT INTO FLIGHT_LISTINGS(
  FlightID, Destination, DepartureDate, DepartureTime, Duration, ArrivalTime, Airline, Price
  )
VALUES
('BC2611232355','Vancouver BC', '2026-11-23', '23:55:00', '01:35:00', '00:30:00', 'WestJet', 203.00),
('ON2612071110', 'Toronto ON', '2026-12-07', '11:10:00', '03:35:00', '15:45:00', 'Flair Airlines', 181.00),
('NY2701130745','New York NY', '2027-01-13', '07:45:00', '04:41:00', '13:26:00', 'Air Canada', 448.00);