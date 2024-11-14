package io6.serializable;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

//类序列化的前提是，类中的所有成员变量是序列化的
@SuppressWarnings("serial")
class Monkey implements Cloneable,Serializable {
	String name;
	int height;
	Weapon goldenCudgel;
	Monkey(String name, int height) {
		this.name = name;
		this.height = height;
		goldenCudgel = new Weapon();
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setHeight(int height) {
		this.height = height;
	}

	public Monkey serializableClone() throws IOException,
			ClassNotFoundException {
		ByteArrayOutputStream baos = new ByteArrayOutputStream(100);
		ObjectOutputStream oos = new ObjectOutputStream(baos);
		oos.writeObject(this);
		 oos.close();baos.close();
		ByteArrayInputStream bais = new ByteArrayInputStream(baos.toByteArray());
		ObjectInputStream ois = new ObjectInputStream(bais);

		Monkey newMonkey = (Monkey) ois.readObject();
		ois.close();bais.close();
		return newMonkey;

	}

	public Monkey clone() throws CloneNotSupportedException {
		return (Monkey) super.clone();
	}
}

