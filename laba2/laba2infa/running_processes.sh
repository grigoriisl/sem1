#!/bin/bash
echo "Все запущенные процессы:"
ps aux
echo "Количество запущенных процессов:"
total=$(ps aux | wc -l)
total1=$((total - 1))
echo $total1
