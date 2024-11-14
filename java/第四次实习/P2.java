package work4;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import com.sun.jdi.Field;

import javax.swing.JTextField;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class P2 extends JFrame implements ActionListener {

	//private static final String JDialog jd  = null;
	private JPanel contentPane;
	private JTextField textField;
	private JPanel panel_1;
	private JPanel panel_2;
	private JPanel panel_3;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					P2 frame = new P2();
					frame.setVisible(true);
					//frame.pack();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public P2() {
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 930, 740);
		setTitle("简易计算器");
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(10, 10, 896, 86);
		contentPane.add(panel);
		panel.setLayout(null);
		
		textField = new JTextField("0");
		textField.setHorizontalAlignment(JTextField.RIGHT);
		textField.setBounds(72, 0, 748, 81);
		panel.add(textField);
		textField.setColumns(10);
		
		panel_1 = new JPanel();
		panel_1.setBounds(11, 101, 895, 86);
		contentPane.add(panel_1);
		String[] name1= {"Back","CE","C","About"};
		for(int i=0;i<4;++i)
		{
			JButton btn = new JButton(name1[i]);
			panel_1.add(btn);
			btn.setForeground(Color.blue) ;
			Font f=new Font("宋体",Font.BOLD,20);
			btn.setFont(f);
			btn.addActionListener(this);
		}
		
		panel_1.setLayout(new GridLayout(1, 4, 1, 1));
		
		panel_2 = new JPanel();
		panel_2.setBounds(10, 197, 471, 496);
		panel_2.setLayout(new GridLayout(4, 3, 1, 1));
		String[] name2= {"9","8","7","6","5","4","3","2","1","0","+/-","."};
		for(int i=0;i<12;++i)
		{
			JButton jbn = new JButton(name2[i]);
			jbn.addActionListener(this);
			/*
			用this监听，每当有按扭被按下就会被监听到
			然后到actionListener唯一的接口方法actionPerformed()去处理
			记得继承接口ActionListener
			即：public class P2 extends JFrame implements ActionListener {···}
			*/
			jbn.setForeground(new Color(200,154,255)); 
			Font f=new Font("宋体",Font.BOLD,20);
			jbn.setFont(f);
			panel_2.add(jbn);
	
		}
		contentPane.add(panel_2);
		
		panel_3 = new JPanel();
		panel_3.setBounds(520, 197, 386, 496);
		contentPane.add(panel_3);
		panel_3.setLayout(new GridLayout(4, 2, 1, 1));
		String[] name3= {"/","sqrt","*","%","-","1/x","+","="};
		for(int i=0;i<8;++i)
		{
			JButton b = new JButton(name3[i]);
			b.addActionListener(this);
			b.setForeground(new Color(250,0,0)); 
			Font f=new Font("宋体",Font.BOLD,20);
			b.setFont(f);
			panel_3.add(b);
		}
		
		
	}
	String prestr="0";
	String result ="0";
	String fuhao =null;
	double dpre =0.0;
	double dcur =0.0;
	double dr=0.0;
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		String str = e.getActionCommand();//获取被监听的按钮值，e是被监听到的对象
		
		if(str.equals("About"))
				{
					JOptionPane.showMessageDialog(null, "zc1.1只能进行简单运算\n         "
							+ ""
							+ "Designed and developed by Mr. Zhang","版本信息", 1);
				}
		if(str.equals("C"))
		{
			textField.setText("0");
			dpre=0;
			dcur=0;
			dr=0;
			prestr="0";
			fuhao  =null;
			result ="0";
			
		}
		if(str.equals("Back"))
		{
			String x=textField.getText();
			if(x.equals("0")||x.equals("0.0"))
			{
				if(fuhao.matches("[\\+\\-/*%]{1}"))
				{
					//System.out.println("0000000");
					fuhao=null;
					textField.setText(prestr);
				}
			}
			else if(x.matches("[.0123456789]*"))
			{
				x=x.substring(0,x.length()-1);
				textField.setText(x);
			}
		    
			
		}
		if(str.equals("CE"))
		{
			textField.setText("0");
			
		}
		if(str.matches("[.0123456789]{1}"))
		{
			
			prestr = textField.getText();
			if(prestr.equals("0.0") || prestr.equals("0"))
			{
				prestr="";
			}
			result=prestr+str;
			//System.out.println(result);
			textField.setText(result);
			
		}
		if(str.matches("[+-/*%]{1}"))
		{
			prestr = textField.getText();
			dpre = Double.parseDouble(prestr);
			fuhao = str;
			this.textField.setText("0");
			
			
		}
		if(str.equals("="))
		{
			 String lstr = textField.getText();
			 
			 dcur = Double.parseDouble(lstr);
			 //System.out.println(dpre);
			 //System.out.println(dcur);
			 dr=0.0;
			switch (fuhao) {
			case "-": {
				
				dr = dpre - dcur;
				break;
			}
			case "+": {
				
				dr = dpre + dcur;
				break;
			}
			case "*": {
				
				dr = dpre * dcur;
				break;
			}
			case "/": {
				if(dcur!=0)
				{
				dr = dpre / dcur;
				break;
				}
			}
			case "%": {
				
				dr = dpre % dcur;
				break;
			}
			
			}
			result=String.valueOf(dr);
			textField.setText(result);
			
		}
		if(str.equals("+/-"))
		{
			prestr = textField.getText();
			double pre = Double.parseDouble(prestr);
			if(pre>0)
			{
				result = '-'+prestr;
			}
			else if(pre == 0)
			{
				result = "0";
			}
			else if(pre<0)
			{
				pre = -pre;
				result = String.valueOf(pre);
			}
			textField.setText(result);
		}
		if(str.equals("1/x"))
		{
			prestr = textField.getText();
			dpre=Double.parseDouble(prestr);
			if(dpre!=0.0)
			{
			dr = 1/dpre;
			result = String.valueOf(dr);
			}
			textField.setText(result);
		}
		if(str.equals("sqrt"))
		{
			prestr = textField.getText();
			dpre=Double.parseDouble(prestr);
			dr = Math.sqrt(dpre);
			result = String.valueOf(dr);
			textField.setText(result);
		}
		
		
	}
}