'''
Aim: Given a string S , encrypt or decrypt it as per the choice entered by the user using Caesar Cipeher Substitution Method
    
Input Format: 
1. The first line provides an option to the user to choose either to encrypt/decrypt
2. In the second line the user inputs the string as per his choice given in part 1.

Note : It is considered that the encrypted string consists of both upper and lowercase letters , while the decrypted strings consist of only uppercase letters.
'''

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
        encrypt_char = encrypt_char.lower()
        final += encrypt_char
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

 '''
 Sample Test Case :
 Case 1 :
        User chooses to input string and encrypt the inputted string.
            input :  
                string : escrsce
                key value  : 5
            output :
                encrypted string : JXHxwhJ
                
 Case 2 :
        User chooses to enter an encrypted string and decrypt it.
            input :
                string : trWEcere
                key value : 6
            output :
                Decrypted String : ZXDKIKXK
                
 Explaination :
    In this program , we take the input string and key value .Once we get the key value , we substitute the alphabet of the string with the updated key value alphabet.
    For eg . if input character is A and key value is 3 , so it will be subsituted by D ( A + 3 = D)
    Also in case if the encrypted string consists of both lower and uppercase characters we convert the whole string to uppercase
    
 '''

            
