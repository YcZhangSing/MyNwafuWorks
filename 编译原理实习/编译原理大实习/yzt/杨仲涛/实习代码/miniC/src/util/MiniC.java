package util;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.JFileChooser;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import myPackage.miniC;
import myPackage.ParseException;

public class MiniC{
	
	Window c;
	JFileChooser jfc;
	int tag = 0;
	String path;
	File file;
	public MiniC(){
		c=new Window();
		c.cancelBtn.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO 自动生成的方法存根
				if(e.getSource() == c.cancelBtn){
					try {
						File lexFile = new File("./output/syncTree.txt");
						FileWriter fileWriter = new FileWriter(lexFile);
						fileWriter.write("");
			            fileWriter.flush();
			            fileWriter.close();
			            
			            miniC.qtList.clear();
			            c.textP1.setText("");
			            c.textP2.setText("");
			            c.textP3.setText("");
			            c.textP4.setText("");
			            c.textP5.setText("");
			            miniC.variableNameGenerator.sequenceId=0;
			            miniC.errorflag=false;
					} catch (FileNotFoundException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					} catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
			}
			
		});
		
		c.openBtn.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO 自动生成的方法存根
				
				if(e.getSource() == c.openBtn){
					File f1 = new File("./output/error.txt");
					if(f1.exists())
						f1.delete();
					File f2 = new File("./output/lexInfo.txt");
					if(f2.exists())
						f2.delete();
					File f3 = new File("./output/qtTable.txt");
					if(f3.exists())
						f3.delete();
					File f4 = new File("./output/syncTree.txt");
					if(f4.exists())
						f4.delete();
					File f5 = new File("./output/syncTree.txt");
					if(f5.exists())
						f5.delete();
					miniC.qtList.clear();
					miniC.tokenTable.clear();
					miniC.variableNameGenerator.clear();
					miniC.errorflag=false;
					miniC.varTable.varTable.clear();
					QTInfo.size = 0;
					
		            jfc=new JFileChooser("./Files");
                    jfc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
					jfc.showDialog(new JLabel(),"选择");
					file=jfc.getSelectedFile();
					path=file.getAbsolutePath();
					System.out.println(path);

					try {
						File rFile=new File(path);
						FileReader fr=new FileReader(rFile);
						c.textP1.read(fr, rFile);
						
						miniC.begin(rFile, tag);
						miniC.lexAnaly();
						miniC.syncTreePrint();
						miniC.QTListPrint();
						miniC.varPrint();

						File lexFile = new File("./output/lexInfo.txt");
						FileReader lexFr = new FileReader(lexFile);
						c.textP2.read(lexFr,lexFile);
						
						File syncFile = new File("./output/syncTree.txt");
						FileReader syncFr = new FileReader(syncFile);
						c.textP3.read(syncFr,syncFile);
						
						File qtTableFile = new File("./output/qtTable.txt");
						FileReader qtTableFr = new FileReader(qtTableFile);
						c.textP4.read(qtTableFr,qtTableFile);
						
						File varFile = new File("./output/varTable.txt");
						FileReader varFr = new FileReader(varFile);
						c.textP5.read(varFr,varFile);
						tag++;
						
						if(miniC.errorflag){
							File errorFile = new File("./output/error.txt");
							FileReader errorFr = new FileReader(errorFile);
							c.textP4.read(errorFr,errorFile);
							JOptionPane.showMessageDialog(null,c.textP4.getText(), "CHECK ERROR",JOptionPane.ERROR_MESSAGE);
						}
						
						miniC.varTable.printList();
						
					} catch (IOException e1) {
						e1.printStackTrace();
					} catch (ParseException e1) {
						// TODO Auto-generated catch block
						//e1.printStackTrace();
						String str = e1.getMessage();
						File errorFile = new File("./output/error.txt");
						try {
							FileWriter errorFw = new FileWriter(errorFile);
							errorFw.append(str);
							FileReader qtTableFr = new FileReader(errorFile);
							c.textP4.read(qtTableFr,errorFile);
						} catch (IOException e2) {
							// TODO 自动生成的 catch 块
							e2.printStackTrace();
						}
					}
				}
				
			}

		});
		
		c.cifa.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e) {
				if(e.getSource() == c.cifa){
					c.textTmp.setViewportView(c.textP2);	
				}
			}
		});
		
		c.yufa.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e) {
				if(e.getSource() == c.yufa){
					c.textTmp.setViewportView(c.textP3);	
				}
			}
		});
		
		c.yuyi.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e) {
				if(e.getSource() == c.yuyi){
					c.textTmp.setViewportView(c.textP4);	
				}
			}
		});
		
		c.fuhao.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e) {
				if(e.getSource() == c.fuhao){
					c.textTmp.setViewportView(c.textP5);	
				}
			}
		});
		
	}
	
	public static void main(String[] args) {
		File f1 = new File("./output/error.txt");
		if(f1.exists())
			f1.delete();
		File f2 = new File("./output/lexInfo.txt");
		if(f2.exists())
			f2.delete();
		File f3 = new File("./output/qtTable.txt");
		if(f3.exists())
			f3.delete();
		File f4 = new File("./output/syncTree.txt");
		if(f4.exists())
			f4.delete();
		File f5 = new File("./output/syncTree.txt");
		if(f5.exists())
			f5.delete();
		MiniC Handle=new MiniC();
	}
}
	
		