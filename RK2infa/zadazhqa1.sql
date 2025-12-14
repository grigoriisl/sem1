--это создание таблиц
CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    group_number VARCHAR(20) NOT NULL
);

CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name VARCHAR(100) NOT NULL
);

CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INTEGER REFERENCES students(student_id),
    subject_id INTEGER REFERENCES subjects(subject_id),
    grade INTEGER CHECK (grade BETWEEN 2 AND 5)
);

CREATE TABLE attendance (
    attendance_id SERIAL PRIMARY KEY,
    student_id INTEGER REFERENCES students(student_id),
    date_attended DATE NOT NULL,
    status VARCHAR(10) CHECK (status IN ('присутствовал', 'отсутствовал'))
);

CREATE TABLE notes (
    note_id SERIAL PRIMARY KEY,
    student_id INTEGER REFERENCES students(student_id),
    note_text TEXT NOT NULL
);

INSERT INTO students (full_name, group_number) VALUES
('Цуп Алексей Игоревич', 'ИУ1-11Б'),
('Слюсаренко Григорий Андреевич', 'ИУ1-11Б'),
('Нагорный Владислав Сергеевич', 'ИУ1-11Б'),
('Стасенко Максим Михайлович', 'ИУ1-11Б'),
('Антонов Алексей Евгеньевич', 'ИУ1-11Б'),
('Крупенко Елена Олеговна', 'ИУ1-11Б');

INSERT INTO subjects (subject_name) VALUES
('Математический анализ'),
('Аналитическая геометрия'),
('Информатика');

INSERT INTO grades (student_id, subject_id, grade) VALUES
(1, 1, 5), (1, 2, 4), (1, 3, 5),
(2, 1, 4), (2, 2, 3), (2, 3, 4),
(3, 1, 5), (3, 2, 5), (3, 3, 5),
(4, 1, 3), (4, 2, 4), (4, 3, 4),
(5, 1, 4), (5, 2, 4), (5, 3, 5),
(6, 1, 5), (6, 2, 5), (6, 3, 4);

INSERT INTO attendance (student_id, date_attended, status) VALUES
(1, '2025-01-10', 'присутствовал'), (1, '2025-01-12', 'присутствовал'),
(2, '2025-01-10', 'присутствовал'), (2, '2025-01-12', 'отсутствовал'),
(3, '2025-01-10', 'присутствовал'), (3, '2025-01-12', 'присутствовал'),
(4, '2025-01-10', 'отсутствовал'), (4, '2025-01-12', 'присутствовал'),
(5, '2025-01-10', 'присутствовал'), (5, '2025-01-12', 'присутствовал'),
(6, '2025-01-10', 'присутствовал'), (6, '2025-01-12', 'отсутствовал');

INSERT INTO notes (student_id, note_text) VALUES
(1, 'Любит информатику'),
(2, 'Нужна помощь по информатике'),
(3, 'Отличник по всем предметам'),
(4, 'Редко посещает занятия по информатике'),
(5, 'Хорошо работает в команде'),
(6, 'Прогресс по информатике');

CREATE INDEX idx_students_group ON students(group_number);
CREATE INDEX idx_grades_student ON grades(student_id);
CREATE INDEX idx_notes_text ON notes USING gin(to_tsvector('russian', note_text));

CREATE VIEW student_avg_grades AS
SELECT s.student_id, s.full_name, ROUND(AVG(g.grade)::numeric, 2) as avg_grade
FROM students s
LEFT JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name;

BEGIN;
WITH new_student AS (
    INSERT INTO students (full_name, group_number) 
    VALUES ('Момотов Артём Сергеевич', 'ИУ1-11Б') 
    RETURNING student_id
)
INSERT INTO grades (student_id, subject_id, grade) 
SELECT student_id, 1, 4 FROM new_student
UNION ALL
SELECT student_id, 2, 5 FROM new_student
UNION ALL
SELECT student_id, 3, 5 FROM new_student;
COMMIT;

SELECT * FROM students 
WHERE group_number = (SELECT group_number FROM students WHERE student_id = 3)
  AND student_id BETWEEN 3-2 AND 3+3
  AND student_id != 3
ORDER BY student_id
LIMIT 5;

SELECT * FROM student_avg_grades WHERE student_id = 3;

SELECT ROUND(AVG(g.grade)::numeric, 2) as avg_informatics
FROM grades g
JOIN subjects s ON g.subject_id = s.subject_id
WHERE s.subject_name = 'Информатика';

SELECT n.note_id, n.student_id, n.note_text
FROM notes n
WHERE to_tsvector('russian', n.note_text) @@ to_tsquery('russian', 'Информатика');

BEGIN;
UPDATE attendance 
SET status = 'отсутствовал'
WHERE student_id = 3 AND date_attended = '2025-01-10';
COMMIT;