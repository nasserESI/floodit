#ifndef BOARDGUI_H
#define BOARDGUI_H
#include <QTableWidget>
#include <QPainter>
#include "couleur.h"
#include "observer.h"
using namespace model;
using namespace nvs;
class boardGUI : public QTableWidget, public nvs::Observer
{
private:
public:
    boardGUI(int row,int color);
    ~boardGUI()override;

    /*!
     * \brief Pure virtual method that each concrete observer must
     * implement: it is this method that the observed subject calls when
     * a notification.
     *
     * \param subject the subject of observation that notifies a change.
     * \see Subject::notifyObservers().
     */
    void Update(const Subject * subject) override;
};

#endif // BOARDGUI_H
