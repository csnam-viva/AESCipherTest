// CryptoTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

#include "cryptopp890/cryptlib.h"
#include "cryptopp890/base64.h"
#include "cryptopp890/aes.h"
#include "cryptopp890/seed.h"
#include "cryptopp890/des.h"
#include "cryptopp890/modes.h"
#include "cryptopp890/filters.h"

template <class EncryptorType>
std::string Encrypt(EncryptorType& encryptor, const std::string& PlainText)
{
	std::string CipherText;
	CryptoPP::StringSource(PlainText, true,
		new CryptoPP::StreamTransformationFilter(
			encryptor, new CryptoPP::Base64Encoder(new CryptoPP::StringSink(CipherText), false) /* default padding */
		)
	);
	return CipherText;
}

template <class DecryptorType>
std::string Decrypt(DecryptorType& decryptor, const std::string& EncText)
{
	std::string PlainText;
	CryptoPP::StringSource(EncText, true,
		new CryptoPP::Base64Decoder(
			new CryptoPP::StreamTransformationFilter(
				decryptor, new CryptoPP::StringSink(PlainText)
			)
		)
	);
	return PlainText;
}

int main()
{
	using namespace std;
	using AES = CryptoPP::AES;

	CryptoPP::SecByteBlock KEY(AES::DEFAULT_KEYLENGTH);
	CryptoPP::SecByteBlock IV(AES::DEFAULT_KEYLENGTH);

	// 임의 값 초기화 
	for (auto& c : KEY) c = 0;
	for (auto& c : IV) c = 0;

	CryptoPP::CBC_Mode<AES>::Encryption Encryptor{ KEY, KEY.size(), IV };
	CryptoPP::CBC_Mode<AES>::Decryption Decryptor{ KEY, KEY.size(), IV };

	try {
		string sText = "Plain Text";
		string sEnc, sDec;

		sEnc = Encrypt(Encryptor, sText);
		cout << sText << " -> " << sEnc << endl;

		sDec = Decrypt(Decryptor, sEnc);
		cout << sEnc << " -> " << sDec << endl;
	}
	catch (exception& ex) {
		cerr << ex.what() << endl;
	}

	return 0;
}