
-- LAB  02 25-9-25

SHOW DATABASES;

CREATE DATABASE CARS;

USE CARS;



CREATE TABLE car(
	reg_num VARCHAR(10) PRIMARY KEY,
    model VARCHAR(10),
    year INT
);

INSERT INTO car(reg_num, model, year)
VALUES
	("KA052250", "Indica", 1990),
	("KA031181", "Lancer", 1957),
    ("KA095477", "Toyota", 1998),
    ("KA053408", "Honda", 2008),
    ("KA041702", "Audi", 2005);



CREATE TABLE person(
	driver_id VARCHAR(10) PRIMARY KEY NOT NULL,
    name VARCHAR(20) NOT NULL,
    address VARCHAR(30) NOT NULL
);

INSERT INTO person(driver_id, name, address)
VALUES
	("A01", "Richard", "Srinivas nagar"),
    ("A02", "Pradeep", "Rajaji nagar"),
    ("A03", "Smith", "Ashok nagar"),
    ("A04", "Venu", "N R Colony "),
    ("A05", "Jhon", "Hanumanth nagar");



CREATE TABLE accident(
	report_num INT PRIMARY KEY NOT NULL ,
    accident_date DATE,
    location VARCHAR(20) 
);

INSERT INTO accident(report_num, accident_date, location)
VALUES
	(11, "2003-01-01", "Mysore Road"),
	(12, "2004-02-02", "South end Circle"),
	(13, "2003-01-21", "Bull temple Road"),
	(14, "2008-02-17", "Mysore Road"),
	(15, "2005-03-04", "Kanakpura Road"); 
    


CREATE TABLE owns(
	driver_id VARCHAR(10) ,
    reg_num VARCHAR(10) ,
    PRIMARY KEY(reg_num, driver_id),
    FOREIGN KEY(driver_id) REFERENCES person(driver_id),
    FOREIGN KEY(reg_num) REFERENCES car(reg_num)
);

INSERT INTO owns(driver_id, reg_num)
VALUES 
	("A01", "KA052250"),
	("A02", "KA053408"),
	("A03", "KA031181"),
	("A04", "KA095477"),
	("A05", "KA041702");
    


CREATE TABLE participated(
	driver_id VARCHAR(10),
    reg_num VARCHAR(10),
    report_num INT,
    damage_amount INT,
    PRIMARY KEY(driver_id, reg_num, report_num),
    FOREIGN KEY(driver_id) REFERENCES person(driver_id),
    FOREIGN KEY(reg_num) REFERENCES car(reg_num),
    FOREIGN KEY(report_num) REFERENCES accident(report_num)
);

INSERT INTO participated(driver_id, reg_num, report_num, damage_amount)
VALUES
	("A01", "KA052250", 11,	10000),
	("A02",	"KA053408",	12,	50000),
    ("A03",	"KA095477",	13,	25000),
    ("A04",	"KA031181",	14,	3000),
    ("A05",	"KA041702",	15,	5000);
    
    

SELECT * FROM participated;

UPDATE participated SET damage_amount = 25000
WHERE reg_num = "KA053408" AND report_num = 12;


INSERT INTO accident
VALUES(16, "2008-03-15", "Domlur");

SELECT * FROM accident;


SELECT accident_date, location FROM accident;


SELECT driver_id FROM participated 
WHERE damage_amount >= 25000;



ALTER TABLE accident RENAME TO accidents;
ALTER TABLE accidents RENAME TO accident;


SELECT MAX(damage_amount) FROM participated;


SELECT COUNT(DISTINCT driver_id) AS COUNT_PEOPLE_WHO_OWNED_CARS_THAT_INVOLVED_AN_ACCIDENT_IN_2008 FROM participated 
WHERE report_num IN (SELECT report_num FROM accident WHERE YEAR(accident_date) = "2008");


SELECT accident_date, location FROM accident;



-- LAB 05 30-10-25

SELECT * FROM PARTICIPATED ORDER BY damage_amount DESC;


SELECT AVG(damage_amount) FROM participated;

-- DELETE FROM PARTICIPATED WHERE damage_amount  < (SELECT AVG(damage_amount) FROM PARTICIPATED);
SELECT name
FROM Person A, Participated B
WHERE 
	A.driver_id = B.driver_id
    AND
    damage_amount > (
		SELECT AVG(damage_amount)
		FROM Participated);


SELECT MAX(damage_amount) 
FROM participated;

