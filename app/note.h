#ifndef NOTE_H
#define NOTE_H

#include <QObject>
#include <QSqlQuery>
#include <QDateTime>

class Note
{
public:
    Note();
    Note(int id, const QString &text);

    QString getNote();
    void setNote(const QString &newNoteText);

    int getID();

    QDateTime getCreationDate();
    QDateTime getLastModified();

private:
    QString noteText;
    int noteID;
    QDateTime noteCreationDate;
    QDateTime noteLastModified;
};

#endif // NOTE_H
