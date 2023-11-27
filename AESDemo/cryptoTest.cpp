//#include <iostream>
//using namespace std;
//
////#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1   
//
//// Crypto++ Includes
//#include "..\download\cryptopp890\cryptlib.h"
//#include "..\download\cryptopp890\Base64.h"
//#include "..\download\cryptopp890\aes.h"        
//#include "..\download\cryptopp890\seed.h"
//#include "..\download\cryptopp890\des.h"
//#include "..\download\cryptopp890\modes.h"      
//#include "..\download\cryptopp890\filters.h"    
//
//#pragma comment(lib, "cryptlib") /
//
//template <class TyMode>
//std::string Encrypt(TyMode& Encryptor, const std::string& PlainText)
//{
//	std::string EncodedText;
//
//	try {
//		CryptoPP::StringSource(PlainText, true,
//			new CryptoPP::StreamTransformationFilter(Encryptor,
//				new CryptoPP::Base64Encoder(
//					new CryptoPP::StringSink(EncodedText), false
//				), CryptoPP::BlockPaddingSchemeDef::ZEROS_PADDING
//			)
//		);
//	}
//	catch (...) {}
//
//	return EncodedText;
//}
//
//template <class TyMode>
//std::string Decrypt(TyMode& Decryptor, const std::string& EncodedText)
//{
//	std::string RecoveredText;
//
//	try {
//		CryptoPP::StringSource(EncodedText, true,
//			new CryptoPP::Base64Decoder(
//				new CryptoPP::StreamTransformationFilter(Decryptor,
//					new CryptoPP::StringSink(RecoveredText),
//					CryptoPP::BlockPaddingSchemeDef::ZEROS_PADDING
//				)
//			)
//		);
//	}
//	catch (...) {}
//
//	return RecoveredText;
//}
//
////template <class Ty>
////std::string CBC_Encrypt(byte* KEY, byte* IV, const std::string& PlainText)
////{
////	typename CryptoPP::CBC_Mode<Ty>::Encryption Encryptor(KEY, Ty::DEFAULT_KEYLENGTH, IV);
////	return Encrypt(Encryptor, PlainText);
////}
////
////
////template <class Ty>
////std::string CBC_Decrypt(byte* KEY, byte* IV, const std::string& PlainText)
////{
////	typename CryptoPP::CBC_Mode<Ty>::Decryption Decryptor(KEY, Ty::DEFAULT_KEYLENGTH, IV);
////	return Decrypt(Decryptor, PlainText);
////}
////
////template <class Ty>
////std::string ECB_Encrypt(byte* KEY, const std::string& PlainText)
////{
////	typename CryptoPP::ECB_Mode<Ty>::Encryption Encryptor(KEY, Ty::DEFAULT_KEYLENGTH);
////	return Encrypt(Encryptor, PlainText);
////}
////
////
////template <class Ty>
////std::string ECB_Decrypt(byte* KEY, const std::string& PlainText)
////{
////	typename CryptoPP::ECB_Mode<Ty>::Decryption Decryptor(KEY, Ty::DEFAULT_KEYLENGTH);
////	return Decrypt(Decryptor, PlainText);
////}
////
////
////template <class CryptoType>
////void Test()
////{
////	using namespace std;
////
////	const std::string sText = "Plain Text";
////	std::string sEnc, sDec;
////
////	byte KEY[CryptoType::DEFAULT_KEYLENGTH] = { 0, };
////	byte IV[CryptoType::BLOCKSIZE] = { 0x01, };
////
////	// CBC 모드
////	sEnc = CBC_Encrypt<CryptoType>(KEY, IV, sText);
////	sDec = CBC_Decrypt<CryptoType>(KEY, IV, sEnc);
////
////	cout << CryptoType::StaticAlgorithmName() << " : " << "CBC_MODE" << endl;
////	cout << sText << "\n -> " << sEnc << "\n -> " << sDec << endl;
////
////
////	// ECB 모드
////	sEnc = ECB_Encrypt<CryptoType>(KEY, sText);
////	sDec = ECB_Decrypt<CryptoType>(KEY, sEnc);
////
////	cout << CryptoType::StaticAlgorithmName() << " : " << "ECB_MODE" << endl;
////	cout << sText << "\n -> " << sEnc << "\n -> " << sDec << endl;
////	cout << endl;
////}
////
////
//////int main()
//////{
//////	using namespace std;
//////
//////	// SEED 
//////	Test<CryptoPP::SEED>();
//////
//////	// AES 
//////	Test<CryptoPP::AES>();
//////
//////	// DES 
//////	Test<CryptoPP::DES>();
//////
//////	return 0;
//////}