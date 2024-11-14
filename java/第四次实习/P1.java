package work4;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JCheckBoxMenuItem;
import java.awt.FlowLayout;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.ButtonGroup;
import javax.swing.JRadioButton;
import javax.swing.JComboBox;
import javax.swing.JList;
import javax.swing.DefaultComboBoxModel;

public class P1 extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	private final ButtonGroup buttonGroup = new ButtonGroup();

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					P1 frame = new P1();
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
	public P1() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		
		JMenuBar menuBar = new JMenuBar();
		menuBar.setToolTipText("");
		setJMenuBar(menuBar);
		
		JMenu mnNewMenu = new JMenu("这是菜单");
		menuBar.add(mnNewMenu);
		
		JMenuBar menuBar_1 = new JMenuBar();
		menuBar_1.setToolTipText("WZXZJ");
		menuBar.add(menuBar_1);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("这是标签->那是文本框");
		lblNewLabel.setBounds(22, 27, 132, 62);
		contentPane.add(lblNewLabel);
		
		textField = new JTextField();
		textField.setBounds(147, 48, 132, 21);
		contentPane.add(textField);
		textField.setColumns(10);
		
		JButton btnNewButton = new JButton("这是按钮1");
		btnNewButton.setBounds(40, 186, 93, 23);
		contentPane.add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("这是按钮2");
		btnNewButton_1.setBounds(264, 186, 93, 23);
		contentPane.add(btnNewButton_1);
		
		JCheckBox chckbxNewCheckBox = new JCheckBox("这是选择框");
		chckbxNewCheckBox.setBounds(22, 98, 103, 23);
		contentPane.add(chckbxNewCheckBox);
		
		JCheckBox chckbxNewCheckBox_1 = new JCheckBox("我们可以多选");
		chckbxNewCheckBox_1.setBounds(22, 123, 103, 23);
		contentPane.add(chckbxNewCheckBox_1);
		
		JRadioButton rdbtnNewRadioButton = new JRadioButton("这是单选框");
		buttonGroup.add(rdbtnNewRadioButton);
		rdbtnNewRadioButton.setBounds(309, 95, 121, 23);
		contentPane.add(rdbtnNewRadioButton);
		
		JRadioButton rdbtnNewRadioButton_1 = new JRadioButton("只能选一个");
		buttonGroup.add(rdbtnNewRadioButton_1);
		rdbtnNewRadioButton_1.setBounds(309, 123, 121, 23);
		contentPane.add(rdbtnNewRadioButton_1);
		
		JComboBox comboBox = new JComboBox();
		comboBox.setModel(new DefaultComboBoxModel(new String[] {"济南", "青岛", "淄博", "沂源", "杨凌", "西安", "扶风", "武汉", "苏州"}));
		comboBox.setBounds(227, 123, 69, 23);
		contentPane.add(comboBox);
		
		JLabel lblNewLabel_1 = new JLabel("这是下拉列表");
		lblNewLabel_1.setBounds(147, 127, 103, 15);
		contentPane.add(lblNewLabel_1);
	}
}
