#include <iostream>
#include <string>
#include <zxing/qrcode/QRCodeWriter.h>
#include <zxing/BarcodeFormat.h>
#include <zxing/common/BitMatrix.h>
#include <zxing/png/PNGWriter.h>

using namespace std;
using namespace zxing;
using namespace zxing::qrcode;
using namespace zxing::png;

int main() {
    string text;
    cout << "Enter text to encode: ";
    getline(cin, text);

    QRCodeWriter writer;
    BitMatrix matrix = writer.encode(text, BarcodeFormat::QR_CODE, 512, 512);

    PNGWriter pngWriter;
    vector<unsigned char> png;
    pngWriter.write(matrix, png);

    FILE* fp = fopen("qrcode.png", "wb");
    fwrite(&png[0], 1, png.size(), fp);
    fclose(fp);

    cout << "QR code generated successfully!" << endl;

    return 0;
}
