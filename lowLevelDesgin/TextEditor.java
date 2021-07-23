import java.util.Stack;
class CharNode {
    char ch;
    CharNode prev;
    CharNode next;

    public CharNode(char ch) { this.ch = ch; }
}

class Edit {
    String operation; //"DEL", "INS", "LEFT", "RIGHT"
    CharNode text;
    public Edit(String operation, CharNode cur) {
        text = cur;
        this.operation = operation;
    }
}

class TextEditor {
    private Stack<Edit> undo_stack;
    private Stack<Edit> redo_stack;
    private CharNode cursor;
    private CharNode end;
    private StringBuilder clipboard;
    private int size; 
    
    public TextEditor() {
        undo_stack = new Stack();
        redo_stack = new Stack();
        end = new CharNode('\0');
        cursor = end;
        size = 0;
        clipboard = new StringBuilder();
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
        CharNode node = new CharNode(ch);
        insert(node);
        undo_stack.push(new Edit("DEL", null));
    }

    public void backspace() {
        if(cursor.prev == null) return;
        undo_stack.push(new Edit("INS", delete(cursor.prev)));
    }

    public void undo() {
        if(undo_stack.isEmpty()) return;
        Edit edit = undo_stack.pop();
        switch(edit.operation) {
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
                insert(edit.text); break;
            default:
                return;
        }
    }
    
    public void redo() {
        if(redo_stack.isEmpty()) return;
        Edit edit = redo_stack.pop();
        switch(edit.operation) {
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
                insert(edit.text); break;
            default:
                return;
        }
    }
    
    public void copy(int startIndex, int endIndex){
        if(startIndex <= 0) startIndex = 0;
        if(endIndex >= size) endIndex = size;
        clipboard = new StringBuilder();
        CharNode node = end.prev;
        int n = size;
        
        while(node != null) {
            if(n < startIndex) break;
            if(cursor != node && n <= endIndex) {
                clipboard.insert(0, node.ch);
            }
            node = node.prev;
            if(cursor != node) n--;
        }
        System.out.println("Clipboard: " + clipboard.toString());
    }
    
    public void paste() {
        for(int i = 0 ; i < clipboard.length(); i++){
            char curr = clipboard.charAt(i);
            insertCharacter(curr);
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        CharNode node = end.prev;
        if(cursor == end) sb.append('|');
        while(node != null) {
            sb.insert(0, node.ch);
            if(cursor == node) sb.insert(0, '|');
            node = node.prev;
        }
        return sb.toString();
    }

    private void insert(CharNode node) {
        CharNode prev = cursor.prev;
        node.next = cursor;
        cursor.prev = node;
        if(prev != null) {
            prev.next = node;
            node.prev = prev;
        }
        size++;
    }

    private CharNode delete(CharNode del) {
        if(del.prev != null) {
            del.prev.next = cursor;
        }
        cursor.prev = del.prev;
        size--;
        return del;
    }
    
    public int getCurrentSize() {
        return size;
    }
}

class Document {
    private
    
    public Document(){
        documents = new HashMap<>();
    }
    
    public TextEditor createDocument(String name) {
        TextEditor textEditor = new TextEditor();
        documents.put(name, textEditor);
        return textEditor;
    }
    
    public void switchDocument(String name) {
        if(documents.containsKey(name))
            return documents.get(name);
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
		
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// Move cursor to the first position
		textEditor.moveCursorLeft();
		textEditor.moveCursorLeft();
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// insert b to make the string abcd 
		textEditor.insertCharacter('b');
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// Move cursor one step to the right 
		textEditor.moveCursorRight();
		
		// backspace b and c 
		textEditor.backspace();
		textEditor.backspace();
	    	System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// Undo backspace things
		textEditor.undo();
		textEditor.undo();
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// redo testing 
		textEditor.redo();
		textEditor.redo();
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// Undo backspace things
		textEditor.undo();
		textEditor.undo();
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		
		// Test the Copy method 
		textEditor.copy(1, 2);
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// Test the Paste method 
		textEditor.paste();
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		
		// Copy again
		textEditor.copy(1,4);
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// Paste again 
		textEditor.paste();
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// Undo backspace things
		textEditor.undo();
		textEditor.undo();
		textEditor.undo();
		textEditor.undo();
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// Undo backspace things
		textEditor.redo();
		textEditor.redo();
		System.out.println("Text : " + textEditor.toString()  + " of size: " + textEditor.getCurrentSize());
		
		// Documents Test 
		private Map<String, TextEditor> documents;
		Document document = new Document();
	
	}
}

