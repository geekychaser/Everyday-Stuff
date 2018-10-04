import java.applet.*;
import java.awt.*;
import java.awt.event.ActionListener;

 public class abc extends Applet implements ActionListener {
    public void init(){
        TextField tf = new TextField();
        tf.setBounds(100, 200, 100, 160);
        Button b = new Button("click menu");

        b.addActionListener(this);
        add(b);
        add(tf);

    }
}

