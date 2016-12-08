#ifndef LICENSEDIALOG_H
#define LICENSEDIALOG_H

#include <QDialog>

namespace Ui {
class LicenseDialog;
}

namespace geometrize
{

namespace dialog
{

/**
 * @brief The LicenseDialog class models the UI for the software license text and notices.
 */
class LicenseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LicenseDialog(QWidget *parent = 0);
    ~LicenseDialog();

private:
    Ui::LicenseDialog *ui;
};

}

}

#endif // LICENSEDIALOG_H