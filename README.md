2. Добавляем страницу /thanks в Nginx
На сервере откройте конфигурационный файл:

bash
nano /etc/nginx/sites-available/astro-neuro-tarot.ru
Внутри блока server { ... } (где listen 443 ssl) добавьте новый location:

nginx
location /thanks {
    default_type text/html;
    return 200 '<!DOCTYPE html><html lang="ru"><head><meta charset="UTF-8"><title>Спасибо!</title></head><body style="text-align:center;margin-top:80px;font-family:Arial,sans-serif"><h2>🌙 Оплата прошла!</h2><p>Благодарим за покупку. Можете вернуться в чат с ботом Макс и начать расклад.</p></body></html>';
}
Полный конфиг после добавления должен выглядеть примерно так:

nginx
server {
    listen 443 ssl;
    server_name astro-neuro-tarot.ru;

    ssl_certificate ...;
    ssl_certificate_key ...;
    # ... (остальные SSL настройки)

    location /webhook {
        proxy_pass http://127.0.0.1:8088;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
    }

    location /yookassa-webhook {
        proxy_pass http://127.0.0.1:8088;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
    }

    # Новая страница "Спасибо"
    location /thanks {
        default_type text/html;
        return 200 '<!DOCTYPE html><html lang="ru"><head><meta charset="UTF-8"><title>Спасибо!</title></head><body style="text-align:center;margin-top:80px;font-family:Arial,sans-serif"><h2>🌙 Оплата прошла!</h2><p>Благодарим за покупку. Можете вернуться в чат с ботом Макс и начать расклад.</p></body></html>';
    }
}
Проверьте и перезагрузите Nginx:

bash
nginx -t
systemctl reload nginx
