import java.io.*;

public class cgbib {
    public static void main(String[] args) {
        String inputFilePath = "./DAE.bib";  // 输入的bib文件路径
        String outputFilePath = "output.bib";  // 输出的bib文件路径

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFilePath));
             BufferedWriter writer = new BufferedWriter(new FileWriter(outputFilePath))) {

            String line;
            while ((line = reader.readLine()) != null) {
                // 查找包含journaltitle的行
                if (line.startsWith("journaltitle")) {
                    // 将journaltitle改为journal
                    line = line.replaceFirst("journaltitle", "journal");
                }
                // 写入修改后的行到输出文件
                writer.write(line);
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Bib file processing completed!");
    }
}
