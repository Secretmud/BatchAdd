#!/bin/sh

while IFS=':' read -r name uid group user_comment home_dir shell pass; do
    sudo groupadd $group && sudo useradd $name -u $uid -p $(mkpasswd -m sha-512 $pass) -G $group -c "$user_comment" -d $home_dir -s $shell
done < file.txt
