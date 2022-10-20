/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package teladepochita;

import javafx.application.Application;
import javafx.event.ActionEvent;
import static javafx.print.PrintColor.COLOR;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.effect.BlendMode;
import javafx.scene.image.Image;
import javafx.scene.layout.Background;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

/**
 *
 * @author 2021122760046
 */
public class TelaDePochita extends Application {
    
    String POCHITA_PNG = "file:data/pochita.png";
    
    @Override
    public void start(Stage primaryStage) {
        Button btn = new Button();
        btn.setText("Press to Pochita");
        
        btn.setOnAction((ActionEvent event) -> {
            System.out.println("Au!");
            primaryStage.setScene(fight());
        });
        
        StackPane root = new StackPane();
        root.getChildren().add(btn);
        
        Scene scene = new Scene(root, 512, 512);
        
        primaryStage.setTitle("Pochita Play!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    
    public Scene fight(){
        Canvas canvas = new Canvas (512, 512);
        GraphicsContext g = canvas.getGraphicsContext2D();
        g.fillRect(0, 0, canvas.getWidth(), canvas.getHeight());
        g.setGlobalBlendMode(BlendMode.SCREEN);
        
        Image iv = new Image(POCHITA_PNG, 512, 512, false, true);
        g.drawImage(iv, 0, 0);
        return (new Scene(new Group(canvas)));
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
