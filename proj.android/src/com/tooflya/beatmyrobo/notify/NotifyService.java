package com.tooflya.beatmyrobo.notify;

import java.util.Timer;
import java.util.TimerTask;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.os.IBinder;

import com.tooflya.beatmyrobo.Game;
import com.tooflya.projectbirds.R;

public class NotifyService extends Service {
	private NotificationManager mNotificationManager;
	private Timer mTimer = new Timer();

	@Override
	public IBinder onBind(Intent intent) {
		return null;
	}

	@Override
	public void onCreate() {
		super.onCreate();

		this.launchCounter();

		System.out.println("I' so started! Service.");
	}

	@Override
	public void onDestroy() {
		super.onDestroy();

		this.shutdownCounter();

		System.out.println("Baaaaad :( Service.");
	}

	private void showNotification() {
		/*
		 * // In this sample, we'll use the same text for the ticker and the //
		 * expanded notification CharSequence text =
		 * getText(R.string.service_started);
		 * 
		 * // Set the icon, scrolling text and timestamp Notification
		 * notification = new Notification(R.drawable.android, text,
		 * System.currentTimeMillis());
		 * 
		 * // The PendingIntent to launch our activity if the user selects this
		 * // notification PendingIntent contentIntent =
		 * PendingIntent.getActivity(this, 0, new Intent(this,
		 * ServiceLauncher.class), 0);
		 * 
		 * // Set the info for the views that show in the notification panel.
		 * notification.setLatestEventInfo(this,
		 * getText(R.string.service_label), text, contentIntent);
		 * 
		 * // Send the notification. // We use a layout id because it is a
		 * unique number. We use it later to // cancel.
		 * nm.notify(R.string.service_started, notification);
		 */

		Notification notification = new Notification(R.drawable.icon, "Как дела?", System.currentTimeMillis());
		Intent notificationIntent = new Intent(this, Game.class);
		PendingIntent pendingIntent = PendingIntent.getActivity(this, 0, notificationIntent, 0); 
		notification.setLatestEventInfo(this.getApplicationContext(), "Как дела?", "Мы всего лишь хотели спросить как у вас дела...", pendingIntent);
		//notification.
		this.mNotificationManager.notify(9999, notification);
	}

	private void launchCounter() {
		this.mNotificationManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);

		this.mTimer.scheduleAtFixedRate(new TimerTask() {
			public void run() {
				System.out.println("I'm here!Service.");
				NotifyService.this.showNotification();
			}
		}, 0, 10000);
	}

	private void shutdownCounter() {
		if (this.mTimer != null) {
			this.mTimer.cancel();
		}
	}
}
