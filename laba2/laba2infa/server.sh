#!/bin/bash
echo "Запуск сервера на порту 8181"
while true; do
    echo "Сообщение получено" | nc -l -p 8181 -q 1
done
