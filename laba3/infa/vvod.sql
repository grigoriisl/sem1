CREATE TABLE products (
	id INT PRIMARY KEY, 
    name VARCHAR(100), 
    price FLOAT,
    quantity INT, 
    category_id INT,
	FOREIGN KEY (category_id) REFERENCES categories(id)
); 

CREATE TABLE categories (
	id INT PRIMARY KEY,
	category_name VARCHAR(100)
);

CREATE TABLE sales (
	id INT PRIMARY KEY,
	product_id INT,
	sale_date DATE,
	quantity_sold INT,
	FOREIGN KEY (product_id) REFERENCES products(id)
);

ы
INSERT INTO categories (id, category_name) VALUES
(1, 'Овощи'),
(2, 'Фрукты'),
(3, 'Молочные продукты'),
(4, 'Мясо'),
(5, 'Бакалея');

INSERT INTO products (id, name, price, quantity, category_id) VALUES
(1, 'Картофель', 45.50, 1000, 1),
(2, 'Морковь', 65.00, 500, 1),
(3, 'Лук', 55.00, 600, 1),
(4, 'Помидоры', 120.00, 300, 1),
(5, 'Огурцы', 90.00, 350, 1),
(6, 'Яблоки', 89.00, 800, 2),
(7, 'Бананы', 95.00, 700, 2),
(8, 'Апельсины', 110.00, 600, 2),
(9, 'Молоко', 65.00, 300, 3),
(10, 'Кефир', 75.00, 250, 3),
(11, 'Сметана', 85.00, 200, 3),
(12, 'Творог', 120.00, 150, 3),
(13, 'Сыр', 450.00, 100, 3),
(14, 'Курица', 250.00, 200, 4),
(15, 'Говядина', 650.00, 100, 4),
(16, 'Свинина', 480.00, 120, 4),
(17, 'Рис', 85.00, 400, 5),
(18, 'Гречка', 95.00, 350, 5),
(19, 'Макароны', 65.00, 500, 5),
(20, 'Мука', 55.00, 600, 5);

INSERT INTO sales (id, product_id, sale_date, quantity_sold) VALUES
(1, '1', '2024-01-15', 5),
(2, '2', '2024-01-15', 3),
(3, '6', '2024-01-16', 2),
(4, '9', '2024-01-16', 1),
(5, '14', '2024-01-17', 1);

--FOREIGN KEY СДЕЛАТЬ 3 НОМЕР