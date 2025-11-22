SELECT p.id, p.name, c.category_name
FROM products p
JOIN categories c ON p.category_id = c.id
WHERE c.category_name = 'Овощи';

SELECT p.id, p.name, p.quantity
FROM products p
WHERE p.quantity > 500;

SELECT SUM(p.price * s.quantity_sold) as total
FROM sales s
JOIN products p ON s.product_id = p.id
WHERE s.sale_date BETWEEN '2024-01-16' AND '2024-01-17';

UPDATE products 
SET quantity = quantity - s.quantity_sold
FROM sales s
WHERE products.id = s.product_id::integer
AND s.id = 1; --ID продажи