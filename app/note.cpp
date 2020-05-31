#include "note.h"

Note::Note()
{

}

Note::Note(int id, const QString &text)
{
    noteID = id;
    noteText = text;
}

void Note::setNote(const QString &newNoteText){
    noteText = newNoteText;
}

QString Note::getNote(){
    return noteText;
}

int Note::getID(){
    return noteID;
}
