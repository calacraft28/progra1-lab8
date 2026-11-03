#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab8pizzaRica.h"

class Lab8pizzaRica : public QMainWindow
{
    Q_OBJECT

public:
    Lab8pizzaRica(QWidget *parent = nullptr);
    ~Lab8pizzaRica();

private:
    Ui::Lab8pizzaRicaClass ui;
};

