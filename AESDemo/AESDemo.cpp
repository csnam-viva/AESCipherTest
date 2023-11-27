// AESDemo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "AES.hpp"
int convert()
{

	std::wstring koreanString = L"안녕하세요"; // 한글 문자열

	for (wchar_t& wchar : koreanString) {
		// ASCII 범위 내의 문자만 처리
		if (wchar <= 127) {
			std::cout << "ASCII value of '" << wchar << "': " << static_cast<int>(wchar) << std::endl;
		}
		else {
			std::cout << "Cannot convert character to ASCII: " << wchar << std::endl;
		}
	}
	return 0;
}

int main()
{


	AES aes128(128); // 128  ECB mode
	
	//std::string plainText = "3243F6A8885A308D313198A2E03707343243F6A8885A308D313198A2E0370734";
	//std::string plainText = "ABCDEFGHIJKLMNOPQRSTUWVXYZABCDEF";

	//std::string str = "AAAAAAAAAAAAAAAA";
	std::string str = "ABCDEFGHIJKLMNOP";
	std::string hexStr = aes128.convertStrToHexStr(str);


	std::string plainText = hexStr; // "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
	//std::string cipherKey = "2B7E151628AED2A6ABF7158809CF4F3C";
	//std::string cipherKey = "12345678901234567890123456789012";
	std::string cipherKey   = "01020304050607080910111213141516";

	//std::cout << "KEY length:" << cipherKey.length() << std::endl;


	std::cout << "origin str : " << str << std::endl;
	std::cout << "Input : " << plainText <<   std::endl;
	
	
	
	std::cout << "KEY length:" << cipherKey.length() << std::endl;
	std::string cipherText = aes128.encryption(plainText, cipherKey, true);
	std::cout << "     Cipher : " << cipherText << std::endl;
	std::string origin = aes128.decryption(cipherText, cipherKey, true);
	std::cout << "origin : " << origin << std::endl;


	std::string decstr = aes128.convertHexStrToStr(origin);
	std::cout << "dec origin : " << decstr << std::endl;


	cipherKey = "04050607090A0B0C0E0F10111314151618191A1B1D1E1F20";
	

	/*
	AES aes192(192);
	plainText = "014BAF2278A69D331D5180103643E99A";
	cipherKey = "E8E9EAEBEDEEEFF0F2F3F4F5F7F8F9FA";

	std::cout << "Input : " << plainText << std::endl;
	cipherText = aes128.encryption(plainText, cipherKey);
	std::cout << "Cipher : " << cipherText << std::endl;
	origin = aes128.decryption(cipherText, cipherKey);
	std::cout << "origin : " << origin << std::endl;

	*/
	/*
	plainText = "76777475F1F2F3F4F8F9E6E777707172";
	cipherKey = "04050607090A0B0C0E0F10111314151618191A1B1D1E1F20";

	std::cout << "\nInput : " << plainText << std::endl;
	cipherText = aes192.encryption(plainText, cipherKey);
	std::cout << "Cipher : " << cipherText << std::endl;
	origin = aes192.decryption(cipherText, cipherKey);
	std::cout << "origin : " << origin << std::endl;


	AES aes256(256);

	plainText = "069A007FC76A459F98BAF917FEDF9521";
	cipherKey = "08090A0B0D0E0F10121314151718191A1C1D1E1F21222324262728292B2C2D2E";
	std::cout << "\nInput : " << plainText << std::endl;
	cipherText = aes256.encryption(plainText, cipherKey);
	std::cout << "Cipher : " << cipherText << std::endl;
	origin = aes256.decryption(cipherText, cipherKey);
	std::cout << "origin : " << origin << std::endl;

	//aes128.setIV(time(NULL));
	std::cout << "\n AES/128/ECB mode\n";
	std::string str = "The current fire house installed within the building used by South Korea's agency for managing the industrial zone will move to the newly built three-story building, the official said.";
	std::string hexStr = aes128.convertStrToHexStr(str);
	cipherKey = "ABCDEFGHIJKLMNOP";
	cipherKey = aes128.convertStrToHexStr(cipherKey);
	std::cout << "Input(Str) : " << str << std::endl;
	std::cout << "Input(Hex) : " << hexStr << std::endl;
	cipherText = aes128.encryption(hexStr, cipherKey);
	std::cout << "Cipher : " << cipherText << std::endl;
	origin = aes128.decryption(cipherText, cipherKey);
	std::cout << "Output(Hex) : " << origin << std::endl;
	std::cout << "Output(Str) : " << aes128.convertHexStrToStr(origin) << std::endl;
	
	std::cout << "\n AES/128/CBC mode\n";
	AES aes128_CBC(128, MODE::CBC);
	std::cout << "Input(Str) : " << str << std::endl;
	std::cout << "Input(Hex) : " << hexStr << std::endl;
	cipherText = aes128_CBC.encryption(hexStr, cipherKey);
	std::cout << "Cipher : " << cipherText << std::endl;
	origin = aes128_CBC.decryption(cipherText, cipherKey);

	std::cout << "Output(Hex) : " << origin << std::endl;
	std::cout << "Output(Str) : " << aes128.convertHexStrToStr(origin) << std::endl;

	*/
  
}
