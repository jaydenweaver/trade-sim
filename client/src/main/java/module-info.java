module com.jayden.tradesim {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.jayden.tradesim to javafx.fxml;
    exports com.jayden.tradesim;
}
