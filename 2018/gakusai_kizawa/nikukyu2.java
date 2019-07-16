import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


public class nikukyu2 extends JFrame implements ActionListener{

    int pt;
    
    JPanel cardPanel;
    JPanel btnPanel;
    
    CardLayout layout;
    CardLayout layout1;

    JButton nextButton1;
    JButton nextButton2;
    JButton nextButton3;
    JButton nextButton4;
    JButton nextButton5;
    JButton nextButton6;
    JButton nextButton7;
    JButton nextButton8;

    JButton btn1;
    JButton btn2;
    JButton btn3;
    JButton btn4;
    JButton btn5;
    JButton btn6;
    JButton btn7;
    JButton btn8;
    JButton btn9;
    JButton btn10;
    JButton btn11;
    JButton btn12;
    JButton btn13;

    JButton bbbbb = new JButton("wtf");
    JButton sssss = new JButton("bbkkbkk");
     
    ImageIcon icon1;
    ImageIcon icon2;
    ImageIcon icon3;
    ImageIcon icon4;
    ImageIcon icon5;
    ImageIcon icon6;
    ImageIcon icon7;
    ImageIcon icon8;
    ImageIcon icon9;
    
    
    JLabel l1;
    JLabel l2;
    JLabel l3;
    JLabel l4;
    JLabel l5;
    JLabel l6;
    JLabel l7;
    JLabel l8;
    JLabel l9;
    JLabel l10;
    JLabel l11;
    JLabel l12;
    JLabel l13;
    JLabel l14;
    JLabel l15;
    JLabel l16;
    JLabel l17;
    JLabel l20;
    
    

  public static void main(String[] args){
    nikukyu2 frame = new nikukyu2();

    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setBounds(100, 70, 1200, 700);
    frame.setTitle("タイトル");
    frame.setVisible(true);
  }

  nikukyu2(){
    super();
    /* カード1 */
    JPanel card1 = new JPanel();
      l1 = new JLabel("肉球");
      l1.setFont(new Font("PLAIN", Font.PLAIN, 60));
      l1.setHorizontalAlignment(JLabel.RIGHT);
     card1.setLayout(new GridLayout(2,2));
      icon1 = new ImageIcon("./uni.jpg");
      icon2 = new ImageIcon("./natuinu.jpg");
      JLabel label1 = new JLabel(icon1);
      JLabel label2 = new JLabel(icon2);
      JLabel label3 = new JLabel("クイズ");
      label3.setFont(new Font("PLAIN", Font.PLAIN, 60));

      card1.add(l1);
      card1.add(label3);
      card1.add(label1);
   //   
      card1.add(label2);

    /* カード2 */
    JPanel card2 = new JPanel();
//    card2.setLayout(new FlowLayout());
      l2 = new JLabel("そもそも肉球とは何でできているでしょう？その成分の内の一つを次から選んでください！");
      l2.setFont(new Font("PLAIN", Font.PLAIN, 25));
      l2.setHorizontalAlignment(JLabel.CENTER);
      card2.add(l2);
    

    /* カード3 */
    JPanel card3 = new JPanel();
    l3 = 
        /*JLabel("正答数"+pt+"/5");*/
        new JLabel("正解はB 脂肪です！");
      l3.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l3.setHorizontalAlignment(JLabel.CENTER);
    card3.add(l3);

//カード4
    JPanel card4 = new JPanel();
    l4 = new JLabel("どちらが猫の肉球でしょう？");
      l4.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l4.setHorizontalAlignment(JLabel.CENTER);
    card4.add(l4);
      
 //カード5
    JPanel card5 = new JPanel();
    card5.setLayout(new GridLayout(3,1));
    l5 = new JLabel("正解はA！");
    JLabel l15;
      l5.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l5.setHorizontalAlignment(JLabel.CENTER);
    l15 = /*new JLabel("正答数"+pt+"/5");*/new JLabel("猫の肉球は汗腺があるからしっとり柔らかい！");
      l15.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l15.setHorizontalAlignment(JLabel.CENTER);
    card5.add(l5);
    card5.add(l15);

 //カード6
    JPanel card6 = new JPanel();
    l6 = new JLabel("犬の先祖と呼ばれる動物はたくさんいるけれど、次の内で犬の先祖は誰でしょう？");
      l6.setFont(new Font("PLAIN", Font.PLAIN, 25));
      l6.setHorizontalAlignment(JLabel.CENTER);
      card6.add(l6);

 //カード7
    JPanel card7 = new JPanel();
    card7.setLayout(new GridLayout(2,1));
    l7 = new JLabel("正解はB！ タイリクオオカミ");
    JLabel l16;
    l16 = new JLabel("実は現在のところはタイリクオオカミもニホンオオカミも犬もDNAでは区別がつかないようですよ！");
   
      l7.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l7.setHorizontalAlignment(JLabel.CENTER);
    //  l16 = new JLabel("正答数"+pt+"/5");
      l16.setFont(new Font("PLAIN", Font.PLAIN, 25));
      l16.setHorizontalAlignment(JLabel.CENTER);
      
    card7.add(l7);
    card7.add(l16);
 //カード8
    JPanel card8 = new JPanel();
    l8 = new JLabel("ピンク色の肉球が存在するのはどっち？");
      l8.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l8.setHorizontalAlignment(JLabel.CENTER);
    card8.add(l8);
 //カード9
    JPanel card9 = new JPanel();
    card9.setLayout(new GridLayout(2,1));
    l9 = new JLabel("正解はA！ 猫");
    JLabel l17;
    l17 = new JLabel("猫は毛色と肉球の色が対応していて、毛が明るい色だと肉球はピンク色になるよ！");
      l9.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l9.setHorizontalAlignment(JLabel.CENTER);
      l17.setFont(new Font("PLAIN", Font.PLAIN, 25));
      l17.setHorizontalAlignment(JLabel.CENTER);
    card9.add(l9);
    card9.add(l17);
 //カード10
    JPanel card10 = new JPanel();
//    card10.setLayout(new GridLayout(2,1));
//      setLayout(new FlowLayout());
    l10 = new JLabel("犬や猫の肉球は前足一本で何個でしょう？　　　　　　　　");
      l10.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l10.setHorizontalAlignment(JLabel.CENTER);
      
      icon6 = new ImageIcon("./inu2.jpg");
      JLabel label6 = new JLabel(icon6);
      
      
      
    card10.add(l10);
    card10.add(label6);
 //カード11

    JPanel card11 = new JPanel();
    l11 = new JLabel("犬や猫の肉球は前足一本で何個でしょう？");
      l11.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l11.setHorizontalAlignment(JLabel.CENTER);
    card11.add(l11);
 //カード12
    JPanel card12 = new JPanel();
    l12 = new JLabel("正解は6個！");
      l12.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l12.setHorizontalAlignment(JLabel.CENTER);
    card12.add(l12);
 //カード13
    JPanel card13 = new JPanel();
    l13 = new JLabel("肉球の部位にはそれぞれ名前があったりします！興味があったら調べてみてください！");
      l13.setFont(new Font("PLAIN", Font.PLAIN, 25));
      l13.setHorizontalAlignment(JLabel.CENTER);
    card13.add(l13);
 //カード14
    JPanel card14 = new JPanel();
    l14 = new JLabel("おつかれさまでした！");
      l14.setFont(new Font("PLAIN", Font.PLAIN, 70));
      l14.setHorizontalAlignment(JLabel.CENTER);
      card14.add(l14);

      
      
      

      
    cardPanel = new JPanel();
    layout = new CardLayout();
    cardPanel.setLayout(layout);

      cardPanel.add(card1);
      cardPanel.add(card2);
      cardPanel.add(card3);
      cardPanel.add(card4);
      cardPanel.add(card5);
      cardPanel.add(card6);
      cardPanel.add(card7);
      cardPanel.add(card8);
      cardPanel.add(card9);
      cardPanel.add(card10);
      cardPanel.add(card11);
      cardPanel.add(card12);
      cardPanel.add(card13);
      cardPanel.add(card14);
//
      

    /* カード移動用ボタン */
//カードa
      JPanel carda = new JPanel();
      /*JButton*/ nextButton1 = new JButton("Next");
      nextButton1.addActionListener(this); //    nextButton.setActionCommand("Next");
      carda.add(nextButton1);   
      nextButton1.setFont(new Font("PLAIN", Font.PLAIN, 20)); nextButton1.setHorizontalAlignment(JLabel.CENTER);
      
      
      /*カードb*/
//      JPanel cardb = new JPanel();

      /*JButton*/ btn1 = new JButton("A 厚い皮");
      btn1.addActionListener(this); //     btn1.setActionCommand("a1");
      btn2 = new JButton("B 脂肪");
      btn2.addActionListener(this);
      btn3 = new JButton("C 毛が固まったもの");
      btn3.addActionListener(this);
      
      JPanel cardb = new JPanel();
      
      btn1.setFont(new Font("PLAIN", Font.PLAIN, 30)); btn1.setHorizontalAlignment(JLabel.CENTER);
      btn2.setFont(new Font("PLAIN", Font.PLAIN, 30)); btn2.setHorizontalAlignment(JLabel.CENTER);
      btn3.setFont(new Font("PLAIN", Font.PLAIN, 30)); 
      btn3.setHorizontalAlignment(JLabel.CENTER);
      
      
      cardb.setLayout(new GridLayout(3,1));
      cardb.add(btn1);
      cardb.add(btn2);
      cardb.add(btn3);
      
//カードc
      JPanel cardc = new JPanel();
      nextButton2 = new JButton("Next");
      nextButton2.addActionListener(this);
      nextButton2.setFont(new Font("PLAIN", Font.PLAIN, 30)); nextButton2.setHorizontalAlignment(JLabel.CENTER);
      cardc.add(nextButton2);      
      
      
//カードd      
      btn4 = new JButton("A");
      btn4.addActionListener(this);
      btn5 = new JButton("B");
      btn5.addActionListener(this);
      btn4.setFont(new Font("PLAIN", Font.PLAIN, 30)); 
      btn4.setHorizontalAlignment(JLabel.CENTER);
      btn5.setFont(new Font("PLAIN", Font.PLAIN, 30)); 
      btn5.setHorizontalAlignment(JLabel.CENTER);
      icon4 = new ImageIcon("./nekonikukyu.jpg");
      icon5 = new ImageIcon("./inuniku.png");
      JLabel label4 = new JLabel(icon4);
      JLabel label5 = new JLabel(icon5);
      JPanel cardd = new JPanel();
  //    cardd.setLayout(new GridLayout(2,1));
      cardd.add(btn4);
      cardd.add(label4);
      cardd.add(btn5);
      cardd.add(label5);
      
//カードe
      JPanel carde = new JPanel();
      nextButton3 = new JButton("Next");
      nextButton3.addActionListener(this);
      nextButton3.setFont(new Font("PLAIN", Font.PLAIN, 30)); nextButton3.setHorizontalAlignment(JLabel.CENTER);
      carde.add(nextButton3);
      
      //カードf
      JPanel cardf = new JPanel();
      cardf.setLayout(new GridLayout(3,1));
      btn6 = new JButton("A アカギツネ");
      btn6.addActionListener(this);
      btn7 = new JButton("B タイリクオオカミ");
      btn7.addActionListener(this);
      btn8 = new JButton("C ニホンタヌキ");
      btn8.addActionListener(this);
      btn6.setFont(new Font("PLAIN", Font.PLAIN, 30)); 
      btn6.setHorizontalAlignment(JLabel.CENTER);
      btn7.setFont(new Font("PLAIN", Font.PLAIN, 30)); btn7.setHorizontalAlignment(JLabel.CENTER);
      btn8.setFont(new Font("PLAIN", Font.PLAIN, 30)); btn8.setHorizontalAlignment(JLabel.CENTER);
      cardf.add(btn6);
      cardf.add(btn7);
      cardf.add(btn8);
      
      //カードg
      JPanel cardg = new JPanel();
      nextButton4 = new JButton("Next");
      nextButton4.addActionListener(this);
      nextButton4.setFont(new Font("PLAIN", Font.PLAIN, 30)); nextButton4.setHorizontalAlignment(JLabel.CENTER);
      cardg.add(nextButton4);
      
      //カードh
      JPanel cardh = new JPanel();
      cardh.setLayout(new GridLayout(2,1));
      btn9 = new JButton("A 猫");
      btn9.addActionListener(this);
      btn10 = new JButton("B 犬");
      btn10.addActionListener(this);
      btn9.setFont(new Font("PLAIN", Font.PLAIN, 30)); 
      btn9.setHorizontalAlignment(JLabel.CENTER);
      btn10.setFont(new Font("PLAIN", Font.PLAIN, 30)); 
      btn10.setHorizontalAlignment(JLabel.CENTER);
      cardh.add(btn9);
      cardh.add(btn10);
      
      
      
      //カードi
      JPanel cardi = new JPanel();
      nextButton5 = new JButton("Next");
      nextButton5.addActionListener(this);
      nextButton5.setFont(new Font("PLAIN", Font.PLAIN, 30)); nextButton5.setHorizontalAlignment(JLabel.CENTER);
      cardi.add(nextButton5);
      
      //カードj
      JPanel cardj = new JPanel();
 //     cardj.setLayout(new GridLayout(3,2));
      nextButton6 = new JButton("Next");
      nextButton6.setFont(new Font("PLAIN", Font.PLAIN, 30)); nextButton6.setHorizontalAlignment(JLabel.CENTER);
      nextButton6.addActionListener(this);
      cardj.add(nextButton6);
     
      //カードk
      JPanel cardk = new JPanel();
      cardk.setLayout(new GridLayout(3,1));
      btn11 = new JButton("A 4個");
      btn11.addActionListener(this);
      btn12 = new JButton("B 5個");
      btn12.addActionListener(this);
      btn13 = new JButton("C 6個");
      btn13.addActionListener(this);
      btn11.setFont(new Font("PLAIN", Font.PLAIN, 30)); btn11.setHorizontalAlignment(JLabel.CENTER);
      btn12.setFont(new Font("PLAIN", Font.PLAIN, 30)); 
      btn12.setHorizontalAlignment(JLabel.CENTER);
      btn13.setFont(new Font("PLAIN", Font.PLAIN, 30)); 
      btn13.setHorizontalAlignment(JLabel.CENTER);
      cardk.add(btn11);
      cardk.add(btn12);
      cardk.add(btn13);
      
      
      
      
      //カードl
      JPanel cardl = new JPanel();
      nextButton7 = new JButton("Next");
      nextButton7.setFont(new Font("PLAIN", Font.PLAIN, 30)); nextButton7.setHorizontalAlignment(JLabel.CENTER);
      nextButton7.addActionListener(this);
      cardl.add(nextButton7);
      
      //カードn
      JPanel cardn = new JPanel();
      nextButton8 = new JButton("Next");
      nextButton8.setFont(new Font("PLAIN", Font.PLAIN, 30)); nextButton8.setHorizontalAlignment(JLabel.CENTER);
      nextButton8.addActionListener(this);
      cardn.add(nextButton8);
      
      //カードm
      JPanel cardm = new JPanel();
      l20 = new JLabel("正答数"+pt+"/5");
      
      l20.setFont(new Font("PLAIN", Font.PLAIN, 40));
      l20.setHorizontalAlignment(JLabel.CENTER);
      cardm.add(l20);
      
      
      
      btnPanel = new JPanel();
      layout1 = new CardLayout();
      btnPanel.setLayout(layout1);
      
      btnPanel.add(carda);
      btnPanel.add(cardb);
      btnPanel.add(cardc);
      btnPanel.add(cardd);
      btnPanel.add(carde);
      btnPanel.add(cardf);
      btnPanel.add(cardg);
      btnPanel.add(cardh);
      btnPanel.add(cardi);
      btnPanel.add(cardj);
      btnPanel.add(cardk);
      btnPanel.add(cardl);
      btnPanel.add(cardn);
      btnPanel.add(cardm);
      
      
/*    JPanel btnPanel = new JPanel();
      btnPanel.add(nextButton);
      btnPanel.add(btn1);
  */
    
    JPanel panel = new JPanel();
//    icon7 = new ImageIcon("./nyanko.jpg");
//    JLabel label7 = new JLabel(icon7);
//    panel.setBackground(Color.BLUE);
    JPanel pan =new JPanel();
    pan.add(bbbbb);
    pan.add(sssss);
    panel.setLayout(new BorderLayout());
    panel.add(cardPanel, BorderLayout.CENTER);
    panel.add(btnPanel, BorderLayout.SOUTH);
 //   panel.add(pan,BorderLayout.NORTH);

    bbbbb.addActionListener(this);
    sssss.addActionListener(this);
    
 //   getContentPane().add(cardPanel, BorderLayout.CENTER);
    getContentPane().add(panel);
  }

  public void actionPerformed(ActionEvent e){
   // String cmd = e.getActionCommand();

  /*  if (cmd.equals("Next")){
        layout.next(cardPanel);
        layout.next(btnPanel);
    }*/
      if (e.getSource() == nextButton1){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          pt=0;
      }
      if (e.getSource() == nextButton2){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == nextButton3){
          layout.next(cardPanel);
          layout1.next(btnPanel);

      }
      if (e.getSource() == nextButton4){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == nextButton5){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == nextButton6){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == nextButton7){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == nextButton8){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          l20.setText("正答数"+pt+"/5");
      }



      if (e.getSource() == bbbbb){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
       if (e.getSource() == sssss){
          layout.previous(cardPanel);
          layout1.previous(btnPanel);
          
      }
      
      
      
      if (e.getSource() == btn1){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == btn2){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          pt++;
          
      }
      if (e.getSource() == btn3){
          layout.next(cardPanel);
          layout1.next(btnPanel);/*
	  layout.next(cardPanel);
          layout1.next(btnPanel);
	  layout.next(cardPanel);
          layout1.next(btnPanel);*/
      }
      if (e.getSource() == btn4){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          pt++;
      }
      if (e.getSource() == btn5){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == btn6){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == btn7){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          pt++;
      }
      if (e.getSource() == btn8){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == btn9){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          pt++;
      }
      if (e.getSource() == btn10){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == btn11){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == btn12){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          
      }
      if (e.getSource() == btn13){
          layout.next(cardPanel);
          layout1.next(btnPanel);
          pt++;
      }
      
  }
}




