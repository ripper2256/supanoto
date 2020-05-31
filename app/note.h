#ifndef NOTE_H
#define NOTE_H

#include <QObject>
#include <QSqlQuery>

class Note
{
public:
    Note();
    Note(int id, const QString &text);

    QString getNote();
    void setNote(const QString &newNoteText);

    int getID();

private:
    QString noteText;
    int noteID;
};

#endif // NOTE_H
