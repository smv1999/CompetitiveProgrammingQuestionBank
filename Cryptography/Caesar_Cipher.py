"""Aim: Given a string S , encrypt or decrypt it as per the choice entered by the user using Caesar Cipeher Substitution Method
    
Input Format: 
1. The first line provides an option to the user to choose either to encrypt/decrypt
2. In the second line the user inputs the string as per his choice given in part 1.
   """






from random import choice

def decrypt(encrypted_string,key_val):
    '''This is the decryption function
    It takes in input encrypted string and key value
    Prints nothing and return the decrypted string value'''
    final = '"'
    encrypted_string = encrypted_string.upper()
    for i in range(len(encrypted_string)):
        decrypt_char = ord(encrypted_string[i]) + key_val
        if (decrypt_char > 90):
            decrypt_char = 65 - ( 90 - decrypt_char)
        decrypt_char = chr(decrypt_char)
        final += decrypt_char
    return final


def encrypt(input_string,key_val):
    '''This is the encryption function
    It takes in input string and key value.
    Prints nothing and return the Encrypted string value'''
    final = ""
    input_string = input_string.upper()
    for i in range(len(input_string)):
        encrypt_char = ord(input_string[i]) + key_val
        if (encrypt_char > 90):
            encrypt_char = 65 - ( 90 - encrypt_char)
        encrypt_char = chr(encrypt_char)
        final += encrypt_char
    final = ''.join(choice((str.upper, str.lower))(char) for char in final)
    return final

#DRIVER CODE

#This is the code for menu , chosing whether to encrypt or decrypt
choose =int(input('CHOOSE FROM THE FOLLOWING : \n 1. Encrypt String \n 2. Decrypt String \n')) 

#This is the code for encryption choice , it calls the function and prints the  encrypted value
if (choose == 1):
    input_string = input('Enter the input text ')
    key_val = int(input('Enter the key value '))
    print('Encrypted string is : ' + encrypt(input_string,key_val))
    
#This is the code for decryption choice , it calls the function and prints the decrypted value
if (choose == 2):
    encrypted_string = input('Enter the encrypted text ')
    key_val = int(input('Enter the key value '))
    print('Decrypted string is : ' + decrypt(encrypted_string,key_val))

       
