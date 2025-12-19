CREATE TABLE categories (
    id SERIAL PRIMARY KEY,
    category_name VARCHAR(100) NOT NULL UNIQUE
);

CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    name VARCHAR(200) NOT NULL,
    price DECIMAL(10, 2) NOT NULL,
    quantity INTEGER NOT NULL DEFAULT 0,
    category_id INTEGER REFERENCES categories(id) ON DELETE RESTRICT
);

CREATE TABLE sales (
    id SERIAL PRIMARY KEY,
    product_id INTEGER REFERENCES products(id) ON DELETE RESTRICT,
    sale_date DATE NOT NULL DEFAULT CURRENT_DATE,
    quantity_sold INTEGER NOT NULL
);

CREATE INDEX idx_categories_name ON categories(category_name);
CREATE INDEX idx_products_name ON products(name);
CREATE INDEX idx_sales_date ON sales(sale_date);