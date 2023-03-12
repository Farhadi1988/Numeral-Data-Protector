/*

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

*/

#include <string>

class NumeralDataProtector
{
private:
    const String Chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;':\"<>,.?/\\";
public:
    int* GetIntArrayFromString(String input, int& length)
    {
        int* intArray = new int[input.length()];
        length = input.length();
        for (int i = 0; i < length; i++)
        {
            intArray[i] = static_cast<int>(input[i]);
        }
        return intArray;
    }

    int* GetIntArrayFromStringDec(String input, int& length)
    {
        int* intArray = new int[input.length()];
        length = 0;
        int pos = 0;
        while (pos < input.length()) {
            int value = 0;
            while (pos < input.length() && input[pos] != '\'') {
                value = value * 10 + (input[pos] - '0');
                pos++;
            }
            intArray[length++] = value;
            pos++;
        }
        return intArray;
    }

    String GetStringFromIntArray(int* input, int length)
    {
        String output;
        for (int i = 0; i < length; i++)
        {
            output += String(input[i]) + "'";
        }
        output.remove(output.length() - 1, 1); // remove the trailing single quote
        return output;
    }

    String GetStringFromIntArrayDec(int* input, int length)
    {
        String output;
        for (int i = 0; i < length; i++)
        {
            output += static_cast<char>(input[i]);
        }
        return output;
    }

    String Encrypt(String plainText, String key)
    {
        int plainTextLength;
        int* plainTextArray = GetIntArrayFromString(plainText, plainTextLength);
        int keyLength;
        int* keyArray = GetIntArrayFromString(key, keyLength);
        int encryptedTextLength = plainTextLength;
        int* encryptedTextArray = new int[encryptedTextLength];
        for (int i = 0; i < plainTextLength; i++)
        {
            encryptedTextArray[i] = (plainTextArray[i] ^ keyArray[i % keyLength]) + ((i + 67) * 2);
        }
        String encryptedText = GetStringFromIntArray(encryptedTextArray, encryptedTextLength);
        delete[] plainTextArray;
        delete[] keyArray;
        delete[] encryptedTextArray;
        return encryptedText;
    }

    String Decrypt(String encryptedText, String key)
    {
        int encryptedTextLength;
        int* encryptedTextArray = GetIntArrayFromStringDec(encryptedText, encryptedTextLength);
        int keyLength;
        int* keyArray = GetIntArrayFromString(key, keyLength);
        int decryptedTextLength = encryptedTextLength;
        int* decryptedTextArray = new int[decryptedTextLength];
        for (int i = 0; i < encryptedTextLength; i++)
        {
            decryptedTextArray[i] = ((encryptedTextArray[i] - ((i + 67) * 2)) ^ keyArray[i % keyLength]);
        }
        String decryptedText = GetStringFromIntArrayDec(decryptedTextArray, decryptedTextLength);
        delete[] encryptedTextArray;
        delete[] keyArray;
        delete[] decryptedTextArray;
        return decryptedText;
    }
};
