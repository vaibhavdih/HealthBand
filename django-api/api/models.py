from django.db import models


class Songs(models.Model):
    heartbeat =models.IntegerField(default=None)
    temperature = models.FloatField(default=None)

    def __str__(self):
        return self.heartbeat



# Create your models here.
