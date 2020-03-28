#include <QLabel>
#include <QLayout>
#include <QComboBox>
#include <QMessageBox>
#include <QSettings>
#include "Device.h"
#include "Gui.h"
#include "Console.h"
#include <math.h>

Device::Device (QWidget * parent):QGroupBox (tr ("Device Info"), parent)
{
    labels = new QVBoxLayout ();
    north = new QHBoxLayout ();
    down = new QHBoxLayout ();
    all = new QHBoxLayout ();

    dID_label = new QLabel ("Device ID: Not Connected", this);
    labels->addWidget(dID_label);
    firm_label = new QLabel ("Firmware Version: Not Connected", this);
    labels->addWidget(firm_label);
    key_label = new QLabel ("Update Key: Not Connected", this);
    labels->addWidget(key_label);
    north->addLayout (labels);
    all->addLayout (north);
    all->addLayout (down);
    setLayout (all);
}
