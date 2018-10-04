
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class ButtonApplet extends Applet implements ActionListener
{
  Button btn;
  Label lab;
  int counter;                                         
  public void init()
  {
    btn = new Button("Click And Count");
    lab = new Label("You click, I count");
 
    btn.addActionListener(this);
    add(btn);   add (lab);
   }
   public void actionPerformed(ActionEvent e)
   {
     lab.setText("Your click count: " + counter++);
   }
}

/* <applet code="ButtonApplet.class" width="300" height="200">
        </applet> */