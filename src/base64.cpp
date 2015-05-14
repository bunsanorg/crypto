#include <bunsan/crypto/base64.hpp>

#include <cryptopp/base64.h>

namespace bunsan{namespace crypto{namespace base64
{
    std::string encode(const unsigned char *data, std::size_t size)
    {
        std::string result;
        CryptoPP::StringSource ss(data, size, true,
            new CryptoPP::Base64Encoder(
                new CryptoPP::StringSink(result),
                /* line break */ false
            )
        );
        return result;
    }

    std::string decode(const unsigned char *data, std::size_t size)
    {
        std::string result;
        CryptoPP::StringSource ss(data, size, true,
            new CryptoPP::Base64Decoder(
                new CryptoPP::StringSink(result)
            )
        );
        return result;
    }
}}}
