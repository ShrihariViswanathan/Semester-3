show databases;


USE Bank_Data_Base;

CREATE TABLE branch(
	branch_name VARCHAR(30) PRIMARY KEY,
    branch_city VARCHAR(30),
    assets REAL
);

desc branch;


CREATE TABLE bank_account(
	account_no INTEGER PRIMARY KEY,
    branch_name VARCHAR(30),
    balance REAL,
    FOREIGN KEY(branch_name) REFERENCES branch(branch_name)
);

desc bank_account;


CREATE TABLE bank_customer(
	customer_name VARCHAR(30) PRIMARY KEY,
    customer_street VARCHAR(30),
    customer_city VARCHAR(30)
);

DESC bank_customer;

CREATE TABLE depositor(
	customer_name VARCHAR(30),
    account_no INTEGER,
    PRIMARY KEY (customer_name, account_no),
    FOREIGN KEY(customer_name) REFERENCES bank_customer(customer_name),
	FOREIGN KEY(account_no) REFERENCES bank_account(account_no)
);

DESC depositor;


CREATE TABLE loan(
	loan_number INTEGER PRIMARY KEY,
    branch_name VARCHAR(30),
    amount REAL,
    FOREIGN KEY(branch_name) REFERENCES branch(branch_name)
);

DESC loan;

INSERT INTO branch VALUES
	("SBI_Chamrajpet", "Bangalore", 50000),
	("SBI_Residency_Road", "Bangalore", 10000),
	("SBI_Shivaji_Road", "Bangalore", 20000),
	("SBI_Parliament_Road", "Bangalore", 10000),
	("SBI_Jantar_Mantar", "Delhi", 20000);


INSERT INTO bank_account VALUES
	(1, "SBI_Chamrajpet", 2000),
	(2, "SBI_Residency_Road", 5000),	
    (3, "SBI_Shivaji_Road", 6000),	
    (4, "SBI_Parliament_Road", 9000),
    (5, "SBI_Jantar_Mantar", 8000),
    (6, "SBI_Shivaji_Road", 4000),
    (8, "SBI_Residency_Road", 5000),
    (9, "SBI_Parliament_Road", 3000),
    (10, "SBI_Residency_Road", 5000),
    (11, "SBI_Jantar_Mantar", 2000);
    
    
INSERT INTO bank_customer VAlUES
	("Avinash", "Bull_Temple_Road", "Bangalore"),
	("Dinesh", "Bannergatta_Road", "Bangalore"),
	("Mohan", "National_College_Road", "Bangalore"),
	("Nikhil", "Akbar_Road", "Delhi"),
	("Ravi", "Prithviraj_Road", "Delhi");
    
INSERT INTO depositor VALUES
	("Avinash", 1),
    ("Avinash", 8),
    ("Dinesh", 2),
    ("Nikhil", 4),
    ("Nikhil", 9),
    ("Dinesh", 10),
    ("Nikhil", 11),
    ("Ravi", 5);
    
INSERT INTO loan VALUES
	(1, 'SBI_Chamrajpet', 1000),
	(2, 'SBI_Residency_Road', 2000),
	(3, 'SBI_Residency_Road', 3000),
	(4, 'SBI_Shivaji_Road', 4000),
	(5, 'SBI_Jantar_Mantar', 5000);
    

SELECT d.customer_name, count(d.customer_name) AS  Number_of_Acoounts, ba.branch_name
FROM depositor d
NATURAL JOIN bank_account ba
GROUP BY d.customer_name, ba.branch_name
HAVING COUNT(d.account_no) >= 2;

SELECT bc.customer_name
FROM bank_customer bc
WHERE NOT EXISTS (
    SELECT branch_name 
    FROM branch 
    WHERE branch_city = "Delhi"
    AND branch_name NOT IN (
        SELECT ba.branch_name 
        FROM depositor d
        JOIN bank_account ba ON d.account_no = ba.account_no
        WHERE d.customer_name = bc.customer_name
    )
);


DELETE FROM bank_account 
WHERE branch_name IN (
	SELECT branch_name 
    FROM branch
    where branch_name = "SBI_Shivaji_Road"
);




    

