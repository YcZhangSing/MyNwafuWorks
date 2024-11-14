package work4;

import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Label;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;


public class ComputerJFrame extends JFrame implements ActionListener{
TextField textOne,textTwo,textResult;
Button getProblem,giveAnswer;
Label operatorLabel,message;
Teacher teacher;

ComputerJFrame(String s){
   super(s);
   teacher = new Teacher();
   setLayout(new FlowLayout());
   textOne=new TextField(10);     //创建textOne,其可见字符长是10
   textTwo=new TextField(10);      //创建textTwo,其可见字符长是10
   textResult=new TextField(10);      //创建textResult,其可见字符长是10
   operatorLabel =new Label("+");  //创建 operatorLabel，初始值“+”
   message = new Label("你还没有回答呢");   //创建message，初始值“你还没有回答呢”
   getProblem = new Button("获取题目"); //创建getProblem，初始值“获取题目”
   giveAnswer = new Button("确认答案"); //创建giveAnswer，初始值“确认答案”
   add(getProblem);
   add(textOne);
   add(operatorLabel);
   add(textTwo);
   add(textResult);
   add(message);
   add(giveAnswer);
  
   //【代码9】//添加若干组件到窗口
   textResult.requestFocus();//【代码10】//textResult 获得焦点
   textOne.setEditable(false);
   textTwo.setEditable(false);//【代码11】//textOne设置textOne和textTwo不可编辑
   getProblem.addActionListener(this);//【代码12】//将当前窗口注册为getProblem的ActionEvent事件监视器    
   giveAnswer.addActionListener(this);//【代码13】//将当前窗口注册为giveAnwser的ActionEvent事件监视器
   textResult.addActionListener(this);//【代码14】//将当前窗口注册为textResult的ActionEvent事件监视器
   setBounds(100, 100, 450,100);//设置出现屏幕上时的初始位置，x=100,y=100,width=450,height=100
   setLocationRelativeTo(null);//【代码16】//设置窗体居中显示
   setVisible(true);//【代码17】//窗口的可见性设置
   validate();
   addWindowFocusListener(new WindowAdapter(){
    public void windowClosing(WindowEvent e){
    System.exit(0);
    }
   }
   );
}

public void actionPerformed(ActionEvent e){
   if(e.getSource()== getProblem)//【代码18】//如果点击了“获取题目 ”)
   {
    int number1 = teacher.giveNumberOne(100);//【代码19】//获取第一个操作数的值
    int number2 = teacher.giveNumberTwo(100);// 【代码20】//获取第二个操作数的值
    String operatorString = teacher.giveOperator();//【代码21】//获取运算符
    textOne.setText(String.valueOf(number1));
    textTwo.setText(String.valueOf(number2));
    operatorLabel.setText(operatorString);//【代码22】//设置图形界面上文本框以及标签的文本，包括：textOne,textTwo,textResult，operatorLabel,message
   }
   if(e.getSource() == giveAnswer )    //【代码23】//如果点击了“确认答案 ”
  {
    String answer =  textResult.getText();//【代码24】//获取文本框中输入的答案
    try{
    		int a = Integer.parseInt(answer);
    		if(teacher.getRight(a))
    		{
    			message.setText("你回答正确");
    		}
    		else if(!teacher.getRight(a))
    		{
    			message.setText("回答错误");
    		}
    		//【代码25】//如果答案正确，message显示“你回答正确”，如果不正确，显示“你回答错误”
    }
    catch(NumberFormatException ex){
    	message.setText("请输入数字字符");//【代码26】//如果输入的不是数字，显示“请输入数字字符”
    }
   }
   textResult.requestFocus();//【代码27】//textResult 获得焦点
   validate();
}
}
