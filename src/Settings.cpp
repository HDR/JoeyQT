#include <QLabel>
#include <QLayout>
#include <QComboBox>
#include <QMessageBox>
#include <QSettings>
#include "Settings.h"
#include "Gui.h"
#include <math.h>

bool Settings::darkmode = 0;
QThread::Priority Settings::priority = QThread::NormalPriority;

Settings::Settings (QWidget * parent):QGroupBox (tr ("Settings"), parent)
{
  QSettings
    set;

  labels = new QVBoxLayout ();
  combo_boxes = new QVBoxLayout ();
  down = new QHBoxLayout ();
  north = new QHBoxLayout ();
  all = new QVBoxLayout ();
  ctype_label = new QLabel ("Cartridge Type:", this);

  labels->addWidget (ctype_label);
  ctype_combo = new QComboBox (this);
  combo_boxes->addWidget (ctype_combo);

  roms_label = new QLabel ("Rom Size:", this);
  labels->addWidget (roms_label);
  roms_combo = new QComboBox (this);
  combo_boxes->addWidget (roms_combo);
  roms_combo->setCurrentIndex (0);

  memty_label = new QLabel ("Memory Type:", this);
  labels->addWidget (memty_label);
  memty_combo = new QComboBox (this);
  combo_boxes->addWidget (memty_combo);
  memty_combo->setCurrentIndex (0);

  rsize_label = new QLabel ("RAM Size:", this);
  labels->addWidget (rsize_label);
  rsize_combo = new QComboBox (this);
  combo_boxes->addWidget (rsize_combo);
  rsize_combo->setCurrentIndex (0);

  GB_check = new QCheckBox (tr ("GB"), this);
  GB_check->setCheckState (Qt::Checked);
  GB_check->setEnabled(false);
  down->addWidget (GB_check);

  GBA_check = new QCheckBox (tr ("GBA"), this);
  GBA_check->setCheckState (Qt::Unchecked);
  down->addWidget (GBA_check);


  north->addLayout (labels);
  north->addLayout (combo_boxes);
  all->addLayout (north);
  all->addLayout (down);
  setLayout (all);

  connect(ctype_combo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Settings::setCtype);
  connect(roms_combo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Settings::setRsize);
  connect(memty_combo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Settings::setMsize);
  connect(rsize_combo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Settings::setMType);
  connect(GBA_check, &QPushButton::clicked, this, &Settings::gbaToggled);
  connect(GB_check, &QPushButton::clicked, this, &Settings::gbToggled);
}

void
Settings::setCtype (int index)
{

}

void
Settings::setRsize (int index)
{

}

void
Settings::setMsize (int index)
{

}

void
Settings::setMType (int type)
{

}

void
Settings::gbToggled ()
{
    if(GB_check->checkState() == Qt::Checked){
        GBA_check->setEnabled(true);
        GB_check->setEnabled(false);
        GBA_check->setCheckState(Qt::Unchecked);
    }
}

void
Settings::gbaToggled ()
{
    if(GBA_check->checkState() == Qt::Checked){
        GB_check->setEnabled(true);
        GBA_check->setEnabled(false);
        GB_check->setCheckState(Qt::Unchecked);
    }
}
