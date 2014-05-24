/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.Computer.Test;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.os.Bundle;

public class ShareTest extends Cocos2dxActivity{
	
    protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);	
	}

    public Cocos2dxGLSurfaceView onCreateView() {
    	Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
    	// ShareTest should create stencil buffer
    	glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
    	
    	return glSurfaceView;
    }

    static {
        System.loadLibrary("cocos2dcpp");
    }   
    
    
    
    
    public static void Share() {
    	  new Thread(new Runnable() {
    	   public void run() {
    	    Intent intent = new Intent("android.intent.action.SEND");
    	    intent.setType("image/*");
    	    intent.putExtra(Intent.EXTRA_SUBJECT, "我的分享");
    	    intent.putExtra(Intent.EXTRA_TEXT, "拍手庆祝吧!!!");
    	    intent.putExtra(
    	      Intent.EXTRA_STREAM,
    	      Uri.parse("file:////data/data/" + acty.getApplicationInfo().packageName + "/share.png"));
    	    System.out.println("/data/data/" + acty.getApplicationInfo().packageName + "/share.png");
    	    intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
    	    acty.startActivity(Intent.createChooser(intent, "分享"));
    	   }
    	  }).start();
    	 }
}
