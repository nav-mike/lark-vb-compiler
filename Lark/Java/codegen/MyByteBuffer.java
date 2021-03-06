/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codegen;

import com.sun.corba.se.impl.ior.ByteBuffer;

/**
 * Класс буфера байт.
 * @version 1.0
 */
public class MyByteBuffer extends ByteBuffer{

    public MyByteBuffer() {
        super(2048);
    }
        
    
    /**
     * Добавить в буфер число размером в 2 байта.
     * @param value Добавляемое значение.
     */
    public void appendShort(short value){
        myEnsureCapacityHelper(elementCount + 2);
	myDoAppend( value ) ;
    }

    @Override
    public void append(String value) {
        super.append(value);
    }

    @Override
    public void append(byte value) {
        super.append(value);
    }

    @Override
    public void append(int value) {
        super.append(value);
    }

    public int getElementCount() {
        return elementCount;
    }
    
    public void copy(MyByteBuffer other){
        int current = this.elementCount;
        int range = this.elementCount;
        
        for (int i = 0; i < other.elementCount; i++){
            
            if (range == 0)
                this.append(other.elementData[i]);
            else{
                this.elementData[current++] = other.elementData[i];
                this.elementCount++;
                range--;
            }
            
        }
        
    }
    
    public void writeShortFrom(int index, short value){
	short current = value ;
	for (int ctr=1; ctr >= 0; ctr--) {
	    elementData[index+ctr] = (byte)(current & 255) ;
	    current = (short) (current >> 8);
	}
    }
    /**
     * This implements the unsynchronized semantics of ensureCapacity.
     * Synchronized methods in this class can internally call this 
     * method for ensuring capacity without incurring the cost of an 
     * extra synchronization.
     *
     * @see java.util.ByteBuffer#ensureCapacity(int)
     */ 
    private void myEnsureCapacityHelper(int minCapacity) {
	int oldCapacity = elementData.length;
	if (minCapacity > oldCapacity) {
	    byte oldData[] = elementData;
	    int newCapacity = (capacityIncrement > 0) ?
		(oldCapacity + capacityIncrement) : (oldCapacity * 2);
    	    if (newCapacity < minCapacity) {
		newCapacity = minCapacity;
	    }
	    elementData = new byte[newCapacity];
	    System.arraycopy(oldData, 0, elementData, 0, elementCount);
	}
    }
    
    /**
     * Добавление двухбайтого числа в буфер.
     * @param value Значение числа.
     */
    private void myDoAppend( short value )
    {
	short current = value ;
	for (int ctr=1; ctr >= 0; ctr--) {
	    elementData[elementCount+ctr] = (byte)(current & 255) ;
	    current = (short) (current >> 8);
	}
	elementCount += 2 ;
    }
}
