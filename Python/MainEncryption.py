import NumeralDataProtector

encryption = NumeralDataProtector.NumeralDataProtector()
key = encryption.generate_random_string(64)

print("\n\n"+"Random String as Password: "+key+"\n\n")

plain_text = "If parents want to give their children a gift,the best thing they can do is to \nteach their children to love challenges, be intrigued by mistakes, enjoy effort, and keep on learning."

print("plain_text: "+plain_text+"\n\n")
encrypted_text = encryption.encrypt(plain_text, key)
print("encrypted_text: "+ encrypted_text+"\n\n")

decrypted_text = encryption.decrypt(encrypted_text, key)
print("decrypted_text: "+ decrypted_text+"\n\n")