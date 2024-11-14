package util;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JTextPane;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Font;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.border.EmptyBorder;
import java.awt.Color;

public class Window {

	public JFrame MyMiniC;
	public JButton openBtn;
	JButton cancelBtn;
	public JScrollPane textSP1;
	public JButton cifa;
	public JButton yufa;
	public JButton yuyi;
	public JButton fuhao;
	public JScrollPane textTmp;
	public JTextArea textTP1;
	public JTextArea textP1;
	public JTextArea textP2;
	public JTextArea textP3;
	public JTextArea textP4;
	public JTextArea textP5;

	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		
		Window window = new Window();
		/*
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MyMimiC window = new MyMimiC();
					//java.awt.Desktop.getDesktop().open(new java.io.File("./test"));
					
					
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});*/
	}

	/**
	 * Create the application.
	 * @wbp.parser.entryPoint
	 */
	public Window() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		MyMiniC = new JFrame();
		MyMiniC.setBounds(100, 100, 520, 635);
		MyMiniC.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel getContentPane = new JPanel();
		getContentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane.setLayout(new BorderLayout(0, 0));
		MyMiniC.setContentPane(getContentPane);
		
		MyMiniC.getContentPane().setFont(new Font("微软雅黑", Font.BOLD, 15));
		
		
		JPanel center=new JPanel(new GridLayout(2,0,0,0));
		
		textSP1 = new JScrollPane();
		textP1 = new JTextArea();
		textP1.setFont(new Font("Monospaced", Font.PLAIN, 22));
		textSP1.setViewportView(textP1);
		center.add(textSP1);
		
		textTmp = new JScrollPane();
		textTP1 = new JTextArea();
		textTP1.setFont(new Font("Monospaced", Font.PLAIN, 22));
		textTmp.setViewportView(textTP1);
		center.add(textTmp);
		
		MyMiniC.getContentPane().add(center, BorderLayout.CENTER);
		
		JScrollPane textSP2 = new JScrollPane();
		textP2 = new JTextArea();
		textSP2.setViewportView(textP2);

		
		JScrollPane textSP3 = new JScrollPane();
		textP3 = new JTextArea();
		textSP3.setViewportView(textP3);

		
		JScrollPane textSP4 = new JScrollPane();
		textP4 = new JTextArea();
		textSP4.setViewportView(textP4);
		
		JScrollPane textSP5 = new JScrollPane();
		textP5 = new JTextArea();
		textSP5.setViewportView(textP5);
		
		
		JPanel east=new JPanel(new GridLayout(6,0,0,0));
		openBtn = new JButton("打开文件");
		openBtn.setBackground(new Color(245, 245, 245));
		openBtn.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		east.add(openBtn);
		fuhao = new JButton("\u7B26\u53F7\u8868");
		fuhao.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		fuhao.setBackground(new Color(245, 245, 245));
		fuhao.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		east.add(fuhao);
		cancelBtn = new JButton("清除");
		cancelBtn.setBackground(new Color(245, 245, 245));
		cancelBtn.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		
		cifa=new JButton("词法分析");
		cifa.setBackground(new Color(245, 245, 245));
		cifa.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		east.add(cifa);
		yufa=new JButton("语法分析");
		yufa.setBackground(new Color(245, 245, 245));
		yufa.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		east.add(yufa);
		yuyi=new JButton("语义分析");
		yuyi.setBackground(new Color(245, 245, 245));
		yuyi.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		east.add(yuyi);
		east.add(cancelBtn);
		

		MyMiniC.getContentPane().add(east, BorderLayout.EAST);
		MyMiniC.setVisible(true);
	}
}
