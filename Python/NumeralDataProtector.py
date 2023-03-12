
"""
Numeral Data Protector v1.4
Author: Mohsen Farhadi
Email: brokeney@gmail.com

Description:
This class contains methods for encrypting and decrypting text using a custom encryption algorithm.
The encryption algorithm uses a randomly generated key and XOR operation to scramble the original text, 
and also converts a given string into an integer array.

This algorithm is versatile and can be executed on multiple platforms and devices, including embedded microcomputers, 
as well as low-level and high-level programming languages. It utilizes text-to-decimal conversion, enabling it to operate 
and preserve data in platforms that do not support complex coding such as Unicode, UTF, and others.

"""


import string
import secrets

class NumeralDataProtector:
    Chars = string.ascii_letters + string.digits + "!@#$%^&*()_+-=[]{}|;':\"<>,.?/\\"

    def __init__(self):
        self.random = secrets.SystemRandom()

    def generate_random_string(self, length):
        return ''.join(self.random.choice(self.Chars) for i in range(length))

    def get_int_array_from_string(self, input):
        return [ord(c) for c in input]

    def get_int_array_from_string_dec(self, input):
        string_array = input.split("'")
        return [int(s) for s in string_array]

    def get_string_from_int_array(self, input):
        return "'".join(str(i) for i in input)

    def get_string_from_int_array_dec(self, input):
        return ''.join(chr(i) for i in input)

    def encrypt(self, plain_text, key):
        plain_text_array = self.get_int_array_from_string(plain_text)
        key_array = self.get_int_array_from_string(key)
        encrypted_text_array = []
        for i in range(len(plain_text_array)):
            encrypted_text_array.append((plain_text_array[i] ^ key_array[i % len(key_array)]) + ((i + 67) * 2))
        return self.get_string_from_int_array(encrypted_text_array)

    def decrypt(self, encrypted_text, key):
        encrypted_text_array = self.get_int_array_from_string_dec(encrypted_text)
        key_array = self.get_int_array_from_string(key)
        decrypted_text_array = []
        for i in range(len(encrypted_text_array)):
            decrypted_text_array.append(((encrypted_text_array[i] - ((i + 67) * 2)) ^ key_array[i % len(key_array)]))
        return self.get_string_from_int_array_dec(decrypted_text_array)