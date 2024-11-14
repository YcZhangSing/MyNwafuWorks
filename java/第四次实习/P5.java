package work4;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class P5 {
    public static void main(String[] args) {
        new Calender().setVisible(true);
    }
}

class Calender extends JFrame implements ActionListener{
    private JButton nextMonth, previousMonth;
    private JPanel pNorth, pCenter, pSouth;
    private JLabel dateLabel;
    private final SimpleDateFormat format = new SimpleDateFormat("yyyy年MM月");
    private Calendar calendar;
    private final String[] Day = {
        "日", "一", "二", "三", "四", "五", "六"
    };
    public void actionPerformed(ActionEvent e) {
        Object obj = e.getSource();
        if(obj == nextMonth) {
            if(calendar.get(Calendar.MONTH) == 11) {
                calendar.roll(Calendar.YEAR, true);
                calendar.set(Calendar.MONTH, 0);
            }
            else calendar.roll(Calendar.MONTH, true);
            addDay();
        }
        else if(obj == previousMonth) {
            if(calendar.get(Calendar.MONTH) == 0) {
                calendar.roll(Calendar.YEAR, false);
                calendar.set(Calendar.MONTH, 11);
            }
            else calendar.roll(Calendar.MONTH, false);
            addDay();
        }
    }
    public void addDay() {
        calendar.set(Calendar.DAY_OF_MONTH, 1);
        int isPosioned = 0;
        pCenter.removeAll();
        for(int i = 0; i < 7; ++i) {
            pCenter.add(new JButton(Day[i]));
            ++isPosioned;
        }

        dateLabel.setText(format.format(calendar.getTime()));
        for(int i = 0; i < calendar.get(Calendar.DAY_OF_WEEK)-1; ++i) {
            pCenter.add(new JLabel());
            ++isPosioned;
        }
        int cnt = 1;
        for(int i = calendar.get(Calendar.DAY_OF_MONTH); i <= calendar.getActualMaximum(Calendar.DAY_OF_MONTH);++i) {
            JLabel label = new JLabel(String.valueOf(cnt++));
            label.setHorizontalAlignment(JLabel.CENTER);
            pCenter.add(label);
            ++isPosioned;
        }
        for(int i = isPosioned; i < 49; ++i) {
            pCenter.add(new JLabel());
        }
        pCenter.updateUI();
    }
    public Calender() {
        super("日历");
        nextMonth = new JButton("下月");
        previousMonth = new JButton("上月");
        dateLabel = new JLabel();
        calendar = Calendar.getInstance();

        nextMonth.addActionListener(this);
        previousMonth.addActionListener(this);

        setLayout(new BorderLayout());
        pNorth = new JPanel();
        pCenter = new JPanel();
        pSouth = new JPanel();
        pNorth.setLayout(new FlowLayout());
        pCenter.setLayout(new GridLayout(7, 7, 0, 0));
        pSouth.setLayout(new FlowLayout());

        pNorth.add(previousMonth);
        pNorth.add(nextMonth);
        pSouth.add(dateLabel);

        addDay();

        add("North", pNorth);
        add("Center", pCenter);
        add("South", pSouth);
        setSize(300, 200);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
