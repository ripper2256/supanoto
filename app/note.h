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
    ~Note() = default;
    Note(const Note &) = default;

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
Q_DECLARE_METATYPE(Note);
#endif // NOTE_H
