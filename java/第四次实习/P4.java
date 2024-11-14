package work4;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JPasswordField;

public class P4 extends JFrame implements FocusListener , ActionListener{

	/**
	 * 
	 */
	String ptUser = "[a-zA-Z]{6,20}";
	String ptpwd = "[a-zA-Z0-9\\p{Punct}]{8,20}";
	String ptEm = "[\\w.]+@[\\w.]+\\.\\w+";
	boolean usrFit = false, pwdFit = false, comFit = false, emFit = false;
	
	 JPanel contentPane;
	JTextField textField = new JTextField();
	 JTextField textField_3;
	 JPasswordField passwordField;
	 JPasswordField passwordField_1;
	 JLabel lblNewLabel_6 = new JLabel("确认密码应与密码相同");
		JLabel lblNewLabel_7 = new JLabel("请输入合法邮箱地址");
		JLabel lblNewLabel_5 = new JLabel("密码必须是8-20位的可含标点或单词的字符串");
		JLabel lblNewLabel_4 = new JLabel("用户名必须是不含空字符的6-10位英文字符串");
		
		
		
		
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					P4 frame = new P4();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public P4() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 484, 335);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("用户名：");
		lblNewLabel.setBounds(24, 23, 82, 15);
		contentPane.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("密码：");
		lblNewLabel_1.setBounds(24, 74, 82, 15);
		contentPane.add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("确认密码：");
		lblNewLabel_2.setBounds(24, 128, 82, 15);
		contentPane.add(lblNewLabel_2);
		
		JLabel lblNewLabel_3 = new JLabel("邮箱：");
		lblNewLabel_3.setBounds(24, 186, 82, 15);
		contentPane.add(lblNewLabel_3);
		
		
		textField.setBounds(236, 20, 145, 21);
		contentPane.add(textField);
		textField.setColumns(10);
		
		textField_3 = new JTextField();
		textField_3.setBounds(236, 183, 145, 21);
		contentPane.add(textField_3);
		textField_3.setColumns(10);
		
		JButton btnNewButton = new JButton("提交");
		btnNewButton.setBounds(77, 230, 97, 23);
		contentPane.add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("取消");
		btnNewButton_1.setBounds(220, 232, 97, 23);
		contentPane.add(btnNewButton_1);
		
		passwordField = new JPasswordField();
		passwordField.setBounds(236, 71, 145, 21);
		contentPane.add(passwordField);
		
		passwordField_1 = new JPasswordField();
		passwordField_1.setBounds(236, 125, 145, 21);
		contentPane.add(passwordField_1);
		
		
		lblNewLabel_4.setBounds(182, 38, 266, 23);
		contentPane.add(lblNewLabel_4);
		
		
		lblNewLabel_5.setBounds(182, 102, 244, 23);
		contentPane.add(lblNewLabel_5);
		
		
		lblNewLabel_6.setBounds(246, 156, 165, 23);
		contentPane.add(lblNewLabel_6);
		
		
		lblNewLabel_7.setBounds(246, 214, 123, 15);
		contentPane.add(lblNewLabel_7);
		lblNewLabel_6.setVisible(false);
		lblNewLabel_5.setVisible(false);
		lblNewLabel_4.setVisible(false);
		lblNewLabel_7.setVisible(false);
		
		btnNewButton_1.addActionListener(this);
		btnNewButton.addActionListener(this);
		textField.addFocusListener(this);
		passwordField.addFocusListener(this);
		passwordField_1.addFocusListener(this);
		textField_3.addFocusListener(this);
	}
	
	@Override
	public void focusGained(FocusEvent e) {
		// TODO Auto-generated method stub
		Object ob= e.getSource();
		if(ob==textField)
		{
			
			lblNewLabel_4.setVisible(true);
		}
		else if(ob==passwordField)
		{
			lblNewLabel_5.setVisible(true);
		}
		else if(ob==passwordField_1)
		{
			lblNewLabel_6.setVisible(true);
		}
		else if(ob==textField_3)
		{
			lblNewLabel_7.setVisible(true);
		}
		
		
	}
String passw;
	@Override
	public void focusLost(FocusEvent e) {
		// TODO Auto-generated method stub
		Object ob= e.getSource();
	
		if(ob==textField)
		{
			String J = textField.getText();
			if(!J.matches(ptUser))
			{
			
			usrFit=false;
			}
			else
			{
				lblNewLabel_4.setVisible(false);
				
				usrFit=true;
			}
		
		}
		else if(ob==passwordField)
		{
			passw=String.valueOf(passwordField.getPassword());
			if(!passw.matches(ptpwd))
			{
			
			pwdFit=false;
			}
			else
			{
				pwdFit=true;
				lblNewLabel_5.setVisible(false);
			}
			
		}
		else if(ob==passwordField_1)
		{
			String J = String.valueOf(passwordField_1.getPassword());
			if((!J.equals(passw)) || !J.matches(ptpwd))
			{
				
				comFit=false;
			}
			else
			{
				comFit=true;
				lblNewLabel_6.setVisible(false);
			}
		}
		else if(ob==textField_3)
		{
			String J = textField_3.getText();
			if(!J.matches(ptEm))
			{
				
				emFit=false;
			}
			else
			{
				emFit=true;
				lblNewLabel_7.setVisible(false);
			}
		}
		
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		String ss = e.getActionCommand();
		if(ss.equals("取消"))
		{
			System.exit(DISPOSE_ON_CLOSE);
			//System.out.print("==========");
		}
		if(ss.equals("提交"))
		{
			if(usrFit == false || pwdFit == false || comFit == false || emFit == false)
			{
				JOptionPane.showMessageDialog(contentPane, "请重新检查");
				//System.out.print("==========");
			}
			else
			{
				JOptionPane.showMessageDialog(contentPane, "注册成功！");
			}
		}
		
	}

	
	
	
	
}
