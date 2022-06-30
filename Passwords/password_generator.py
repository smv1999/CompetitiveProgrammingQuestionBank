#generating hard and random password

import random

lower_char="abcdefghijklmnopqrstuvwxyz"
upper_char="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
number="1234567890"
special_char="!@#$%^&*"

total= lower_char+upper_char+number+special_char

length_of_password=10

password="".join(random.sample(total,length_of_password))

print("your genereted password is",password)
