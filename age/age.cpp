#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Enter your Age"); //display at window above as enter your age

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal); //take Horizontal position
    spinBox->setRange(0,130); //limit the age of spinBox
    slider->setRange(0,130);    //limit slider of age
    //set connection and tell what they have to change
    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                                slider,SLOT(setValue(int)));    //connect to slider
    QObject::connect(slider,SIGNAL(valueChange(int)),
                            spinBox,SLOT(setValue(int))); //connect to spinBox
    spinBox->setValue(35); //set default value

    QHBoxLayout *layout = new QHBoxLayout; //create the layout
    layout->addWidget(spinBox); 
    layout->addWidget(slider);
    window->setLayout(layout);

    window->show();//show the whole of the window

    return app.exec();
}
