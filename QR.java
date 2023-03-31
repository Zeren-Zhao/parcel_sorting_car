import java.io.File;
import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Path;

import com.google.zxing.BarcodeFormat;
import com.google.zxing.EncodeHintType;
import com.google.zxing.WriterException;
import com.google.zxing.client.j2se.MatrixToImageWriter;
import com.google.zxing.common.BitMatrix;
import com.google.zxing.qrcode.QRCodeWriter;

public class QRCodeGenerator {

    public static void main(String[] args) {

        String text = "CO4 3SQ"; //The text need transfered

        int width = 350; // Img width
        int height = 350; // Img height
        String format = "png"; // Img format

        // Setting QRcode parameters
        QRCodeWriter qrCodeWriter = new QRCodeWriter();
        BitMatrix bitMatrix;
        try {
            bitMatrix = qrCodeWriter.encode(text, BarcodeFormat.QR_CODE, width, height);
        } catch (WriterException e) {
            e.printStackTrace();
            return;
        }

        // Write the QR code into Img file
        Path path = FileSystems.getDefault().getPath("output.png");
        try {
            MatrixToImageWriter.writeToPath(bitMatrix, format, path);
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("QR code has already stored in file 'output.png.'");
    }

}
