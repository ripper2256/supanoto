#include "note.h"

Note::Note()
{

}

Note::Note(int id, const QString &text)
{
    noteID = id;
    noteText = text;
    noteCreationDate = QDateTime::currentDateTime();
}

void Note::setNote(const QString &newNoteText){
    noteText = newNoteText;
    noteLastModified = QDateTime::currentDateTime();
}

QString Note::getNote(){
    return noteText;
}

int Note::getID(){
    return noteID;
}

QDateTime Note::getCreationDate(){
    return noteCreationDate;
}

QDateTime Note::getLastModified(){
    return noteLastModified;
}
