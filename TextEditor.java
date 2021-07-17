import java.util.Stack;
class CharNode {
    char ch;
    CharNode prev;
    CharNode next;

    public CharNode(char ch) { this.ch = ch; }
}

class Edit {
    String edition; //"DEL", "INS", "LEFT", "RIGHT"
    CharNode data;
    public Edit(String edition, CharNode cur) {
        data = cur;
        this.edition = edition;
    }
}

class TextEditor {
    private Stack<Edit> undo_stack;
    private Stack<Edit> redo_stack;
    private CharNode cursor;
    private CharNode end;

    public TextEditor() {
        undo_stack = new Stack();
        redo_stack = new Stack();
        end = new CharNode('\0');
        cursor = end;
    }

    public void moveCursorLeft() {
        if(cursor.prev == null) return;
        cursor = cursor.prev;
        undo_stack.push(new Edit("RIGHT", null));
    }

    public void moveCursorRight() {
        if(cursor == end) return;
        cursor = cursor.next;
        undo_stack.push(new Edit("LEFT", null));
    }

    public void insertCharacter(char ch) {
        CharNode n = new CharNode(ch);
        insert(n);
        undo_stack.push(new Edit("DEL", null));
    }

    public void backspace() {
        if(cursor.prev == null) return;
        undo_stack.push(new Edit("INS", delete(cursor.prev)));
    }

    public void undo() {
        if(undo_stack.isEmpty()) return;
        Edit edit = undo_stack.pop();
        switch(edit.edition) {
            case "LEFT":{
                redo_stack.push(new Edit("RGIHT", null));
                cursor = cursor.prev; break;
            }
            case "RIGHT":
                redo_stack.push(new Edit("LEFT", null));
                cursor = cursor.next; break;
            case "DEL":
                redo_stack.push(new Edit("INS", cursor.prev));
                delete(cursor.prev); break;
            case "INS":
                redo_stack.push(new Edit("DEL", null));
                insert(edit.data); break;
            default:
                return;
        }
    }
    
    public void redo() {
        if(redo_stack.isEmpty()) return;
        Edit edit = redo_stack.pop();
        switch(edit.edition) {
            case "LEFT":
                undo_stack.push(new Edit("RIGHT", null));
                cursor = cursor.prev; break;
            case "RIGHT":
                undo_stack.push(new Edit("LEFT", null));
                cursor = cursor.next; break;
            case "DEL":
                undo_stack.push(new Edit("INS", cursor.prev));
                delete(cursor.prev); break;
            case "INS":
                undo_stack.push(new Edit("DEL", null));
                insert(edit.data); break;
            default:
                return;
        }
    }


    public String toString() {
        StringBuilder text = new StringBuilder();
        CharNode n = end.prev;
        if(cursor == end) text.append('|');
        while(n != null) {
            text.insert(0, n.ch);
            if(cursor == n) text.insert(0, '|');
            n = n.prev;
        }
        return text.toString();
    }

    private void insert(CharNode node) {
        CharNode prev = cursor.prev;
        node.next = cursor;
        cursor.prev = node;
        if(prev != null) {
            prev.next = node;
            node.prev = prev;
        }
    }

    private CharNode delete(CharNode del) {
        if(del.prev != null) {
            del.prev.next = cursor;
        }
        cursor.prev = del.prev;
        return del;
    }
}


public class Main
{
	public static void main(String[] args) {
		TextEditor textEditor = new TextEditor();
		
		// insert 
		textEditor.insertCharacter('a');
		textEditor.insertCharacter('c');
		textEditor.insertCharacter('d');
		
		System.out.println(textEditor.toString());
		
		// Move cursor to the first position
		textEditor.moveCursorLeft();
		textEditor.moveCursorLeft();
		System.out.println(textEditor.toString());
		
		
		// insert b to make the string abcd 
		textEditor.insertCharacter('b');
		System.out.println(textEditor.toString());
		
		// Move cursor one step to the right 
		textEditor.moveCursorRight();
		
		
		// backspace b and c 
		textEditor.backspace();
		textEditor.backspace();
		System.out.println(textEditor.toString());
		
		
		// Undo backspace things
		textEditor.undo();
		textEditor.undo();
		System.out.println(textEditor.toString());
		
		// redo testing 
		textEditor.redo();
		textEditor.redo();
		System.out.println(textEditor.toString());
		
		// Undo backspace things
		textEditor.undo();
		textEditor.undo();
		System.out.println(textEditor.toString());
	
	}
}

